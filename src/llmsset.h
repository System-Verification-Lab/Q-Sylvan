/*
 * Copyright 2011-2014 Formal Methods and Tools, University of Twente
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef LLMSSET_H
#define LLMSSET_H

#ifndef LLMSSET_MASK
#define LLMSSET_MASK 0 // set to 1 to use bit mask instead of modulo
#endif

typedef struct llmsset
{
    uint64_t          *table;       // table with hashes
    uint8_t           *data;        // table with values
    size_t            max_size;     // maximum size of the hash table (for resizing)
    size_t            table_size;   // size of the hash table (number of slots) --> power of 2!
#if LLMSSET_MASK
    size_t            mask;         // size-1
#endif
    size_t            f_size;
    int16_t           threshold;    // number of iterations for insertion until returning error
} *llmsset_t;

// Every key is 16 bytes, also inserted data same size, also padded size is 16 bytes
#define LLMSSET_LEN 16

/**
 * Translate an index to a pointer (data array)
 */
static inline void*
llmsset_index_to_ptr(const llmsset_t dbs, size_t index)
{
    return dbs->data + index * LLMSSET_LEN;
}

/**
 * Create and free a lockless MS set
 */
llmsset_t llmsset_create(size_t initial_size, size_t max_size);
void llmsset_free(llmsset_t dbs);

/**
 * Retrieve maximum size of lockless MS set.
 */
static inline size_t
llmsset_get_max_size(const llmsset_t dbs)
{
    return dbs->max_size;
}

/**
 * Retrieve current size of lockless MS set.
 */
static inline size_t
llmsset_get_size(const llmsset_t dbs)
{
    return dbs->table_size;
}

/**
 * Set size of set.
 * Typically called during garbage collection, after clear and before rehash.
 * Returns 0 if dbs->table_size > dbs->max_size!
 */
static inline int
llmsset_set_size(llmsset_t dbs, size_t size)
{
    if (size > dbs->max_size) return 0;
    dbs->table_size = size;
#if LLMSSET_MASK
    /* Warning: if size is not a power of two, this will certainly cause issues */
    dbs->mask = dbs->table_size - 1;
#endif
    dbs->threshold = (64 - __builtin_clzl(dbs->table_size)) + 4; // doubling table_size increases threshold by 1
    return 1;
}

/**
 * Core function: find existing data, or add new
 * Returns NULL when not found and no available bucket in the hash table.
 */
void *llmsset_lookup(const llmsset_t dbs, const void *data, uint64_t *insert_index, int *created, uint64_t *index);

/**
 * To perform garbage collection, the user is responsible that no lookups are performed during the process.
 *
 * 1) call llmsset_clear or llmsset_clear_multi
 * 2) call llmsset_mark for each entry to keep
 * 3) call llmsset_rehash or llmsset_rehash_multi
 *
 * Note that the _multi variants use numa_tools
 */
void llmsset_clear(const llmsset_t dbs);
void llmsset_clear_multi(const llmsset_t dbs, size_t my_id, size_t n_workers);

/**
 * llmsset_mark_... returns a non-zero value when the node was unmarked
 * The _safe version uses a CAS operation, the _unsafe version a normal memory operation.
 * Use the _unsafe version unless you are bothered by false negatives
 */
int llmsset_is_marked(const llmsset_t dbs, uint64_t index);
int llmsset_mark_unsafe(const llmsset_t dbs, uint64_t index);
int llmsset_mark_safe(const llmsset_t dbs, uint64_t index);

void llmsset_rehash(const llmsset_t dbs);
void llmsset_rehash_multi(const llmsset_t dbs, size_t my_id, size_t n_workers);

/**
 * Some information retrieval methods
 */
void llmsset_print_size(llmsset_t dbs, FILE *f);
size_t llmsset_get_filled(const llmsset_t dbs);
size_t llmsset_get_filled_partial(const llmsset_t dbs, size_t start, size_t end);
size_t llmsset_get_insertindex_multi(const llmsset_t dbs, size_t my_id, size_t n_workers);

/**
 * Self-test for internal method
 */
void llmsset_test_multi(const llmsset_t dbs, size_t n_workers);

#endif
