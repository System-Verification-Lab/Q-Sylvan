#include "cmap.h"

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include "util/atomics.h"
#include "util/cmap.h"
#include "util/fast_hash.h"
#include "util/util.h"

#undef CACHE_LINE
#undef CACHE_LINE_SIZE

#define CACHE_LINE 8
#define CACHE_LINE_SIZE 256


typedef union {
    complex_t       c;
    uint64_t        d[2];
} bucket_t;


static const uint64_t EMPTY = 14738995463583502973ull;
static const uint64_t LOCK  = 14738995463583502974ull;
static const uint64_t CL_MASK = -(1ULL << CACHE_LINE);

struct cmap_s {
    size_t              size;
    size_t              mask;
    size_t              threshold;
    int                 seen_0;
    bucket_t  __attribute__(( __aligned__(32)))       *table;
    // Q: should this 32 change to 16 now that we use doubles instead of
    // long doubles for the real and imaginary components?
};


void 
print_bucket_floats(bucket_t *b)
{
    printf("%.60f, %.60f\n", b->c.r, b->c.i);
}

void 
print_bucket_bits(bucket_t* b)
{
    printf("hex = %lx, %lx\n", b->d[0], b->d[1]);
}

bool
cmap_find_or_put (const cmap_t *cmap, const complex_t *v, ref_t *ret)
{
    // TODO: round based on number of significant digits rather than
    // some absolute value
    complex_t rounded;
    rounded.r = round(v->r * TOLERANCE)/TOLERANCE;
    rounded.i = round(v->i * TOLERANCE)/TOLERANCE;

    uint32_t            hash = SuperFastHash(&rounded, sizeof(complex_t), 0);
    uint32_t            prime = odd_primes[hash & PRIME_MASK];
    bucket_t *val = (bucket_t *) &rounded;
    assert (val->d[0] != LOCK && val->d[0] != EMPTY);

    for (int c = 0; c < cmap->threshold; c++) {
        size_t              ref = hash & cmap->mask;
        size_t              line_end = (ref & CL_MASK) + CACHE_LINE_SIZE;
        for (size_t i = 0; i < CACHE_LINE_SIZE; i++) {
            bucket_t           *bucket = &cmap->table[ref];
            if (bucket->d[0] == EMPTY) {
                if (cas(&bucket->d[0], EMPTY, LOCK)) {
                    *ret = ref;
                    //atomic_write (&bucket->d[3], val->d[3]);
                    //atomic_write (&bucket->d[2], val->d[2]);
                    atomic_write (&bucket->d[1], val->d[1]);
                    atomic_write (&bucket->d[0], val->d[0]);
                    return 0;
                }
            }
            while (atomic_read(&bucket->d[0]) == LOCK) {}

            if (    bucket->d[0] == val->d[0] &&
                    bucket->d[1] == val->d[1] //&&
                    //bucket->d[2] == val->d[2] &&
                    //bucket->d[3] == val->d[3]
                    ) {
                *ret = ref;
                return 1;
            }
            ref += 1;
            ref = ref == line_end ? line_end - CACHE_LINE_SIZE : ref;
        }
        hash += prime << CACHE_LINE;
    }
    assert ("Hash table full" && false);
}

complex_t *
cmap_get (const cmap_t *cmap, const ref_t ref)
{
    return &cmap->table[ref].c;
}

cmap_t *
cmap_create (int size)
{
    cmap_t  *cmap = calloc (1, sizeof(cmap_t));
    cmap->size = 1ull << size;
    cmap->mask = cmap->size - 1;
    cmap->table = calloc (cmap->size, sizeof(bucket_t));
    for (int c = 0; c < cmap->size; c++) {
        cmap->table[c].d[0] = EMPTY;
    }
    cmap->threshold = cmap->size / 100;
    cmap->threshold = min(cmap->threshold, 1ULL << 16);
    cmap->seen_0 = 0;
    return cmap;
}

void
cmap_free (cmap_t *cmap)
{
    free (cmap->table);
    free (cmap);
}
