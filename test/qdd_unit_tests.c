#include <stdio.h>

#include "sylvan.h"
#include "test_assert.h"
#include "sylvan_qdd_int.h"

bool VERBOSE = true;

int test_cmap()
{
    cmap_t *ctable = cmap_create(10);

    ref_t index1, index2;
    complex_t val1, val2, val3;
    int found;

    val1 = Cmake(3.5, 4.7);
    found = cmap_find_or_put(ctable, &val1, &index1); test_assert(found == 0);
    for(int k=0; k<10; k++){
        found = cmap_find_or_put(ctable, &val1, &index2);
        test_assert(found == 1);
        test_assert(index2 == index2);
    }

    val1 = Cmake(0.9, 2/3);
    val2 = Cmake(0.9, 2/3);
    found = cmap_find_or_put(ctable, &val1, &index1); test_assert(found == 0);
    found = cmap_find_or_put(ctable, &val2, &index2); test_assert(found == 1);
    test_assert(index1 == index2);

    val1 = Cmake(Qmake(0,1,2),0); // 1/sqrt(2)
    val2 = Cmake(Qmake(0,1,2),0);
    found = cmap_find_or_put(ctable, &val1, &index1); test_assert(found == 0);
    found = cmap_find_or_put(ctable, &val2, &index2); test_assert(found == 1);
    test_assert(index1 == index2);

    val3 = *cmap_get(ctable, index1);
    test_assert(fabs(val3.r - val1.r) < TOLERANCE);
    test_assert(fabs(val3.i - val1.i) < TOLERANCE);
    
    if(VERBOSE) printf("cmap tests:           ok\n");
    cmap_free(ctable);
    return 0;
}

int test_complex_operations()
{
    init_amplitude_table(20);

    complex_t ref1, ref2, ref3, ref4, val1, val2, val3, val4;
    cint index1, index2, index3, index4;

    // test C_ZERO
    ref1 = Cmake(0.0, 0.0);         index1 = Clookup(ref1);
    ref2 = Cmake(0.0, 0.0);         index2 = Clookup(ref2);
    test_assert(index1 == index2);
    test_assert(index1 == C_ZERO);

    // test C_ONE
    ref1 = Cmake(1.0, 0.0);         index1 = Clookup(ref1);
    ref2 = Cmake(1.0, 0.0);         index2 = Clookup(ref2);
    test_assert(index1 == index2);
    test_assert(index1 == C_ONE);

    // Clookup, Cvalue
    ref1 = Cmake(0.5, 0.0);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(0.5, 0.0);         index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(Qmake(0,1,2),0);   index3 = Clookup(ref3);   val3 = Cvalue(index3);
    ref4 = Cmake(Qmake(0,1,2),0);   index4 = Clookup(ref4);   val4 = Cvalue(index4);
    test_assert(index1 == index2);  test_assert(CexactEqual(val1, val2));
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));

    // Cnegative
    ref1 = Cmake(0.3, 4.2);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(-0.3, -4.2);       index2 = Clookup(ref2);   val2 = Cvalue(index2);
    index3 = Cnegative(index1);     val3 = Cvalue(index3);
    index4 = Cnegative(index2);     val4 = Cvalue(index4);
    test_assert(index1 == index4);  test_assert(CexactEqual(val1, val4));
    test_assert(index2 == index3);  test_assert(CexactEqual(val2, val3));

    // Cadd
    ref1 = Cmake(5.2, 1.0);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(-0.3,7.0);         index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(4.9, 8.0);         index3 = Clookup(ref3);   val3 = Cvalue(index3);
    index4 = Cadd(index1, index2);  val4 = Cvalue(index4);
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));

    // Csub
    ref1 = Cmake(1/3, 3.5);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(1/3,-1.2);         index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(0.0, 4.7);         index3 = Clookup(ref3);   val3 = Cvalue(index3);
    index4 = Csub(index1, index2);  val4 = Cvalue(index4);
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));
    
    // Cmul
    ref1 = Cmake(3.0, 5.0);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(0.5, 7.0);         index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(-33.5, 23.5);      index3 = Clookup(ref3);   val3 = Cvalue(index3);
    index4 = Cmul(index1, index2);  val4 = Cvalue(index4);
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));

    ref1 = Cmake(Qmake(0,1,2),0);   index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(Qmake(0,1,2),0);   index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(0.5, 0.0);         index3 = Clookup(ref3);   val3 = Cvalue(index3);
    index4 = Cmul(index1, index2);  val4 = Cvalue(index4);
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));

    // Cdiv
    ref1 = Cmake(1.3,-0.7);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(1.0, 0.0);         index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(1.3,-0.7);         index3 = Clookup(ref3);   val3 = Cvalue(index3);
    index4 = Cdiv(index1, index2);  val4 = Cvalue(index4);
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));

    ref1 = Cmake(5.0, 9.0);         index1 = Clookup(ref1);   val1 = Cvalue(index1);
    ref2 = Cmake(-4.0,7.0);         index2 = Clookup(ref2);   val2 = Cvalue(index2);
    ref3 = Cmake(43./65., -71./65.);index3 = Clookup(ref3);   val3 = Cvalue(index3);
    index4 = Cdiv(index1, index2);  val4 = Cvalue(index4);
    test_assert(index3 == index4);  test_assert(CexactEqual(val3, val4));

    if(VERBOSE) printf("complex operations:   ok\n");
    free_amplitude_table();
    return 0;
}

int test_basis_state_creation()
{
    init_amplitude_table(20);
    bool x[] = {0};
    
    QDD q0, q1;
    x[0] = 0; q0 = create_basis_state(1, x);
    x[0] = 1; q1 = create_basis_state(1, x);

    AMP a;
    x[0] = 0; a = qdd_get_amplitude(q0, x); test_assert(a == C_ONE);
    x[0] = 1; a = qdd_get_amplitude(q0, x); test_assert(a == C_ZERO);
    x[0] = 0; a = qdd_get_amplitude(q1, x); test_assert(a == C_ZERO);
    x[0] = 1; a = qdd_get_amplitude(q1, x); test_assert(a == C_ONE);

    QDD q2, q3;
    bool x3[] = {0, 0, 0};
    x3[2] = 0; x3[1] = 0; x3[0] = 0; q2 = create_basis_state(3, x3);
    x3[2] = 1; x3[1] = 0; x3[0] = 1; q3 = create_basis_state(3, x3);

    x3[2] = 0; x3[1] = 0; x3[0] = 0; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ONE);
    x3[2] = 0; x3[1] = 0; x3[0] = 1; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);
    x3[2] = 0; x3[1] = 1; x3[0] = 0; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);
    x3[2] = 0; x3[1] = 1; x3[0] = 1; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 0; x3[0] = 0; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 0; x3[0] = 1; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 1; x3[0] = 0; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 1; x3[0] = 1; a = qdd_get_amplitude(q2, x3); test_assert(a == C_ZERO);

    x3[2] = 0; x3[1] = 0; x3[0] = 0; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);
    x3[2] = 0; x3[1] = 0; x3[0] = 1; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);
    x3[2] = 0; x3[1] = 1; x3[0] = 0; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);
    x3[2] = 0; x3[1] = 1; x3[0] = 1; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 0; x3[0] = 0; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 0; x3[0] = 1; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ONE);
    x3[2] = 1; x3[1] = 1; x3[0] = 0; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);
    x3[2] = 1; x3[1] = 1; x3[0] = 1; a = qdd_get_amplitude(q3, x3); test_assert(a == C_ZERO);

    // TODO: also test node count

    printf("basis state creation: ok\n");
    free_amplitude_table();
    return 0;
}

int test_vector_addition()
{
    init_amplitude_table(20);
    
    QDD q0, q1, q00, q01, q10, q11, q000, q001, q010, q100;
    bool x[] = {0};
    bool x4[] = {0, 0, 0, 0};
    AMP a;

    LACE_ME;

    // Single qubit test
    x[0] = 0; q0 = create_basis_state(1, x);
    x[0] = 1; q1 = create_basis_state(1, x);
    q00 = qdd_plus(q0, q0);
    q01 = qdd_plus(q0, q1);
    q10 = qdd_plus(q1, q0);
    q11 = qdd_plus(q1, q1);
    q000 = qdd_plus(q00, q0);
    q001 = qdd_plus(q00, q1);
    q010 = qdd_plus(q01, q0);
    q100 = qdd_plus(q10, q0);

    x[0] = 0; a = qdd_get_amplitude(q00, x); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x[0] = 1; a = qdd_get_amplitude(q00, x); test_assert(a == C_ZERO);
    x[0] = 0; a = qdd_get_amplitude(q01, x); test_assert(a == C_ONE);
    x[0] = 1; a = qdd_get_amplitude(q01, x); test_assert(a == C_ONE);
    x[0] = 0; a = qdd_get_amplitude(q10, x); test_assert(a == C_ONE);
    x[0] = 1; a = qdd_get_amplitude(q10, x); test_assert(a == C_ONE);
    x[0] = 0; a = qdd_get_amplitude(q11, x); test_assert(a == C_ZERO);
    x[0] = 1; a = qdd_get_amplitude(q11, x); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    test_assert(q01 == q10);

    x[0] = 0; a = qdd_get_amplitude(q000, x); test_assert(a == Clookup(Cmake(3.0, 0.0)));
    x[0] = 1; a = qdd_get_amplitude(q000, x); test_assert(a == C_ZERO);
    x[0] = 0; a = qdd_get_amplitude(q001, x); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x[0] = 1; a = qdd_get_amplitude(q001, x); test_assert(a == C_ONE);
    x[0] = 0; a = qdd_get_amplitude(q010, x); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x[0] = 1; a = qdd_get_amplitude(q010, x); test_assert(a == C_ONE);
    x[0] = 0; a = qdd_get_amplitude(q100, x); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x[0] = 1; a = qdd_get_amplitude(q100, x); test_assert(a == C_ONE);
    test_assert(q001 == q010);
    test_assert(q001 == q100);
    


    // 4 qubit test
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 0; q0 = create_basis_state(4, x4);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 0; q1 = create_basis_state(4, x4);
    q00 = qdd_plus(q0, q0);
    q01 = qdd_plus(q0, q1);
    q10 = qdd_plus(q1, q0);
    q11 = qdd_plus(q1, q1);
    q000 = qdd_plus(q00, q0);
    q001 = qdd_plus(q00, q1);
    q010 = qdd_plus(q01, q0);
    q100 = qdd_plus(q10, q0);

    // TODO: better way to assert "all others 0" --> creating function which
    // returns array x from int will help
    // q0 + q0
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q00, x4); test_assert(a == C_ZERO);

    // q0 + q1 / q1 + q0
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ONE);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ONE);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q01, x4); test_assert(a == C_ZERO);
    assert(q01 == q10);

    // q1 + q1
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q11, x4); test_assert(a == C_ZERO);

    // q0 + q0 + q0
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == Clookup(Cmake(3.0, 0.0)));
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q000, x4); test_assert(a == C_ZERO);

    // q0 + q0 + q1 / q0 + q1 + q0 / q1 + q0 + q0
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == Clookup(Cmake(2.0, 0.0)));
    x4[3] = 0; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 0; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ONE);
    x4[3] = 1; x4[2] = 0; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 0; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 0; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    x4[3] = 1; x4[2] = 1; x4[1] = 1; x4[0] = 1; a = qdd_get_amplitude(q001, x4); test_assert(a == C_ZERO);
    assert(q001 == q010);
    assert(q001 == q100);

    if(VERBOSE) printf("qdd vector addition:  ok\n");
    free_amplitude_table();
    return 0;
}

int test_x_gate()
{
    init_amplitude_table(20);

    QDD q0, q1, q2, q3, q4, q5;
    bool x[] = {0};
    bool x3[] = {0, 0, 0};

    LACE_ME;

    // Single qubit test
    x[0] = 0; q0 = create_basis_state(1, x);
    x[0] = 1; q1 = create_basis_state(1, x);
    x[0] = 0; q2 = create_basis_state(1, x);

    q0 = qdd_gate(q0, GATEID_X, 0); test_assert(q0 == q1);
    q0 = qdd_gate(q0, GATEID_X, 0); test_assert(q0 == q2);
    q0 = qdd_gate(q0, GATEID_X, 0); test_assert(q0 == q1);
    q0 = qdd_gate(q0, GATEID_X, 0); test_assert(q0 == q2);

    // 3 qubit test
    x3[2] = 0; x3[1] = 0; x3[0] = 0; q3 = create_basis_state(3, x3);
    x3[2] = 0; x3[1] = 1; x3[0] = 0; q4 = create_basis_state(3, x3);
    x3[2] = 0; x3[1] = 1; x3[0] = 1; q5 = create_basis_state(3, x3);
    
    q3 = qdd_gate(q3, GATEID_X, 1); test_assert(q3 == q4);
    q3 = qdd_gate(q3, GATEID_X, 0); test_assert(q3 == q5);

    if(VERBOSE) printf("qdd x gates:          ok\n");
    free_amplitude_table();
    return 0;
}

int test_h_gate()
{
    init_amplitude_table(20);

    QDD q0, q1, q2, q3, q4, q5;
    bool x[] = {0};
    bool x2[] = {0,0};
    AMP a;

    LACE_ME;

    // Single qubit test
    x[0] = 0; q0 = create_basis_state(1, x);
    x[0] = 1; q1 = create_basis_state(1, x);

    q0 = qdd_gate(q0, GATEID_H, 0);
    q1 = qdd_gate(q1, GATEID_H, 0);

    x[0] = 0; a = qdd_get_amplitude(q0, x); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x[0] = 1; a = qdd_get_amplitude(q0, x); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x[0] = 0; a = qdd_get_amplitude(q1, x); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x[0] = 1; a = qdd_get_amplitude(q1, x); test_assert(a == Clookup(Cmake(Qmake(0,-1,2),0)));


    // Two qubit test
    x2[1] = 0; x2[0] = 0; q2 = create_basis_state(2, x2); // |00>
    x2[1] = 0; x2[0] = 1; q3 = create_basis_state(2, x2); // |01>
    x2[1] = 0; x2[0] = 0; q4 = create_basis_state(2, x2); // |00>
    x2[1] = 0; x2[0] = 0; q5 = create_basis_state(2, x2); // |00>
    q2 = qdd_gate(q2, GATEID_H, 0); // q2 = |0+>
    q3 = qdd_gate(q3, GATEID_H, 0); // q3 = |0->
    q4 = qdd_gate(q4, GATEID_H, 1); // q4 = |+0>
    q5 = qdd_gate(q5, GATEID_H, 0);
    q5 = qdd_gate(q5, GATEID_H, 1); // q5 = |++>

    // q2 = |0+>
    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q2, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q2, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q2, x2); test_assert(a == C_ZERO);
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q2, x2); test_assert(a == C_ZERO);

    // q3 = |0->
    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q3, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q3, x2); test_assert(a == Clookup(Cmake(Qmake(0,-1,2),0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q3, x2); test_assert(a == C_ZERO);
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q3, x2); test_assert(a == C_ZERO);

    // q4 = |+0>
    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q4, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q4, x2); test_assert(a == C_ZERO);
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q4, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q4, x2); test_assert(a == C_ZERO);

    // q5 = |++>
    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q5, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q5, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q5, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q5, x2); test_assert(a == Clookup(Cmake(0.5, 0)));

    if(VERBOSE) printf("qdd h gates:          ok\n");
    free_amplitude_table();
    return 0;
}

int test_phase_gates()
{
    init_amplitude_table(20);

    QDD q0, qZ, qS, qSS, qT, qTT, qTTTT;
    bool x2[] = {0, 0};
    AMP a;

    LACE_ME;

    // simple 2 qubit test
    x2[1] = 0; x2[0] = 0; q0 = create_basis_state(2, x2);
    q0 = qdd_gate(q0, GATEID_H, 0);
    q0 = qdd_gate(q0, GATEID_H, 1);

    qZ    = qdd_gate(q0, GATEID_Z, 0);
    qS    = qdd_gate(q0, GATEID_S, 0);
    qSS   = qdd_gate(qS, GATEID_S, 0);
    qT    = qdd_gate(q0, GATEID_T, 0);
    qTT   = qdd_gate(qT, GATEID_T, 0);
    qTTTT = qdd_gate(qTT, GATEID_T, 0);
    qTTTT = qdd_gate(qTTTT, GATEID_T, 0);

    test_assert(qZ == qSS);
    test_assert(qS == qTT);
    test_assert(qZ == qTTTT);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));

    q0 = qdd_gate(q0, GATEID_Z, 0);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));

    q0 = qdd_gate(q0, GATEID_Z, 0);
    q0 = qdd_gate(q0, GATEID_Z, 1);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));

    q0 = qdd_gate(q0, GATEID_Z, 1);
    q0 = qdd_gate(q0, GATEID_S, 0);
    q0 = qdd_gate(q0, GATEID_S, 0);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));

    q0 = qdd_gate(q0, GATEID_Z, 0);
    q0 = qdd_gate(q0, GATEID_T, 1);
    q0 = qdd_gate(q0, GATEID_T, 1);
    q0 = qdd_gate(q0, GATEID_T, 1);
    q0 = qdd_gate(q0, GATEID_T, 1);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(q0, x2); test_assert(a == Clookup(Cmake(-0.5,0)));

    if(VERBOSE) printf("qdd phase gates:      ok\n");
    free_amplitude_table();
    return 0;
}

int test_cx_gate()
{
    init_amplitude_table(20);

    QDD qBell;
    bool x2[] = {0,0};
    AMP a;

    LACE_ME;

    // Test Bell state
    x2[1] = 0; x2[0] = 0; qBell = create_basis_state(2, x2);
    qBell = qdd_gate(qBell, GATEID_H, 0);
    
    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(qBell, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(qBell, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(qBell, x2); test_assert(a == C_ZERO);
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(qBell, x2); test_assert(a == C_ZERO);


    qBell = qdd_cgate(qBell, GATEID_X, 0, 1);
    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(qBell, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(qBell, x2); test_assert(a == C_ZERO);
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(qBell, x2); test_assert(a == C_ZERO);
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(qBell, x2); test_assert(a == Clookup(Cmake(Qmake(0,1,2),0)));

    // TODO: more tests

    if(VERBOSE) printf("qdd cnot gates:       ok\n");
    free_amplitude_table();
    return 0;
}

int test_cz_gate()
{
    init_amplitude_table(20);

    QDD qGraph;
    bool x2[] = {0, 0};
    AMP a;

    LACE_ME;

    // 2 qubit graph state
    x2[1] = 0; x2[0] = 0; qGraph = create_basis_state(2, x2);
    qGraph = qdd_gate(qGraph, GATEID_H, 0);
    qGraph = qdd_gate(qGraph, GATEID_H, 1);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));

    qGraph = qdd_cgate(qGraph, GATEID_Z, 0, 1);

    x2[1] = 0; x2[0] = 0; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 0; x2[0] = 1; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 0; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(0.5, 0)));
    x2[1] = 1; x2[0] = 1; a = qdd_get_amplitude(qGraph, x2); test_assert(a == Clookup(Cmake(-0.5,0)));

    if(VERBOSE) printf("qdd CZ gates:         ok\n");
    free_amplitude_table();
    return 0;
}

int test_10qubit_circuit()
{
    init_amplitude_table(20);

    QDD q, qref;
    bool x10[] = {0,0,0,0,0,0,0,0,0,0};
    
    LACE_ME;

    // 10 qubit state
    qref = create_basis_state(10, x10);
    q    = create_basis_state(10, x10);

    // 30 random* Clifford gates            *chosen by a fair dice roll
    q = qdd_cgate(q, GATEID_X, 1, 3);       q = qdd_gate(q, GATEID_H, 0);
    q = qdd_gate(q, GATEID_X, 6);           q = qdd_cgate(q, GATEID_X, 6, 9);
    q = qdd_gate(q, GATEID_H, 4);           q = qdd_cgate(q, GATEID_X, 3, 5);
    q = qdd_gate(q, GATEID_H, 1);           q = qdd_gate(q, GATEID_X, 1);
    q = qdd_cgate(q, GATEID_X, 3, 8);       q = qdd_cgate(q, GATEID_Z, 3, 6);
    q = qdd_gate(q, GATEID_Z, 3);           q = qdd_cgate(q, GATEID_X, 0, 7);
    q = qdd_cgate(q, GATEID_X, 1, 9);       q = qdd_gate(q, GATEID_H, 4);
    q = qdd_cgate(q, GATEID_X, 0, 2);       q = qdd_gate(q, GATEID_X, 2);
    q = qdd_cgate(q, GATEID_X, 5, 8);       q = qdd_cgate(q, GATEID_X, 0, 4);
    q = qdd_cgate(q, GATEID_X, 0, 8);       q = qdd_cgate(q, GATEID_X, 6, 9);
    q = qdd_cgate(q, GATEID_X, 0, 9);       q = qdd_gate(q, GATEID_X, 9);
    q = qdd_cgate(q, GATEID_X, 4, 9);       q = qdd_cgate(q, GATEID_Z, 2, 7);
    q = qdd_cgate(q, GATEID_Z, 7, 8);       q = qdd_gate(q, GATEID_X, 7);
    q = qdd_gate(q, GATEID_Z, 2);           q = qdd_gate(q, GATEID_Z, 7);
    q = qdd_gate(q, GATEID_X, 6);           q = qdd_gate(q, GATEID_X, 1);
    // inverse
    q = qdd_gate(q, GATEID_X, 1);           q = qdd_gate(q, GATEID_X, 6);
    q = qdd_gate(q, GATEID_Z, 7);           q = qdd_gate(q, GATEID_Z, 2);
    q = qdd_gate(q, GATEID_X, 7);           q = qdd_cgate(q, GATEID_Z, 7, 8);
    q = qdd_cgate(q, GATEID_Z, 2, 7);       q = qdd_cgate(q, GATEID_X, 4, 9);
    q = qdd_gate(q, GATEID_X, 9);           q = qdd_cgate(q, GATEID_X, 0, 9);
    q = qdd_cgate(q, GATEID_X, 6, 9);       q = qdd_cgate(q, GATEID_X, 0, 8);
    q = qdd_cgate(q, GATEID_X, 0, 4);       q = qdd_cgate(q, GATEID_X, 5, 8);
    q = qdd_gate(q, GATEID_X, 2);           q = qdd_cgate(q, GATEID_X, 0, 2);
    q = qdd_gate(q, GATEID_H, 4);           q = qdd_cgate(q, GATEID_X, 1, 9);
    q = qdd_cgate(q, GATEID_X, 0, 7);       q = qdd_gate(q, GATEID_Z, 3);
    q = qdd_cgate(q, GATEID_Z, 3, 6);       q = qdd_cgate(q, GATEID_X, 3, 8);
    q = qdd_gate(q, GATEID_X, 1);           q = qdd_gate(q, GATEID_H, 1);
    q = qdd_cgate(q, GATEID_X, 3, 5);       q = qdd_gate(q, GATEID_H, 4);
    q = qdd_cgate(q, GATEID_X, 6, 9);       q = qdd_gate(q, GATEID_X, 6);
    q = qdd_gate(q, GATEID_H, 0);           q = qdd_cgate(q, GATEID_X, 1, 3);

    test_assert(equivalent(q, qref, 10, false, VERBOSE)); // check approx equiv
    test_assert(equivalent(q, qref, 10, true,  VERBOSE)); // check exact equiv
    test_assert(q == qref);

    if(VERBOSE) printf("qdd 10 qubit circuit: ok\n");
    free_amplitude_table();
    return 0;
}

int test_20qubit_circuit()
{
    init_amplitude_table(20);

    QDD q, qref;
    bool x20[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    LACE_ME;

    // 20 qubit state
    qref = create_basis_state(20, x20);
    q    = create_basis_state(20, x20);

    // 100 gates
    q = qdd_cgate(q, GATEID_Z, 4, 18);      q = qdd_gate(q, GATEID_H, 16);          q = qdd_cgate(q, GATEID_X, 1, 12);      q = qdd_gate(q, GATEID_Z, 4);
    q = qdd_cgate(q, GATEID_Z, 9, 10);      q = qdd_cgate(q, GATEID_Z, 0, 4);       q = qdd_cgate(q, GATEID_Z, 1, 16);      q = qdd_cgate(q, GATEID_Z, 13, 16);
    q = qdd_cgate(q, GATEID_Z, 7, 11);      q = qdd_cgate(q, GATEID_X, 3, 5);       q = qdd_cgate(q, GATEID_Z, 1, 4);       q = qdd_cgate(q, GATEID_X, 6, 16);
    q = qdd_cgate(q, GATEID_X, 3, 18);      q = qdd_cgate(q, GATEID_X, 2, 15);      q = qdd_cgate(q, GATEID_X, 7, 10);      q = qdd_gate(q, GATEID_Z, 6);
    q = qdd_cgate(q, GATEID_X, 3, 6);       q = qdd_cgate(q, GATEID_Z, 11, 16);     q = qdd_cgate(q, GATEID_X, 5, 19);      q = qdd_gate(q, GATEID_Z, 18);
    q = qdd_cgate(q, GATEID_Z, 14, 15);     q = qdd_cgate(q, GATEID_Z, 10, 12);     q = qdd_gate(q, GATEID_H, 8);           q = qdd_gate(q, GATEID_X, 9);
    q = qdd_gate(q, GATEID_X, 8);           q = qdd_cgate(q, GATEID_X, 7, 18);      q = qdd_gate(q, GATEID_X, 17);          q = qdd_gate(q, GATEID_Z, 11);
    q = qdd_cgate(q, GATEID_X, 12, 16);     q = qdd_gate(q, GATEID_X, 18);          q = qdd_gate(q, GATEID_Z, 4);           q = qdd_gate(q, GATEID_X, 18);
    q = qdd_cgate(q, GATEID_X, 4, 10);      q = qdd_gate(q, GATEID_X, 15);          q = qdd_cgate(q, GATEID_Z, 16, 18);     q = qdd_cgate(q, GATEID_Z, 0, 15);
    q = qdd_cgate(q, GATEID_X, 7, 10);      q = qdd_gate(q, GATEID_X, 18);          q = qdd_gate(q, GATEID_Z, 16);          q = qdd_cgate(q, GATEID_X, 7, 18);
    q = qdd_gate(q, GATEID_X, 16);          q = qdd_gate(q, GATEID_X, 2);           q = qdd_cgate(q, GATEID_X, 9, 10);      q = qdd_gate(q, GATEID_X, 6);
    q = qdd_gate(q, GATEID_X, 18);          q = qdd_gate(q, GATEID_Z, 11);          q = qdd_cgate(q, GATEID_Z, 4, 5);       q = qdd_gate(q, GATEID_X, 1);
    q = qdd_cgate(q, GATEID_Z, 2, 19);      q = qdd_cgate(q, GATEID_X, 8, 9);       q = qdd_cgate(q, GATEID_Z, 10, 12);     q = qdd_cgate(q, GATEID_Z, 11, 16);
    q = qdd_cgate(q, GATEID_X, 13, 19);     q = qdd_cgate(q, GATEID_Z, 1, 3);       q = qdd_gate(q, GATEID_X, 6);           q = qdd_gate(q, GATEID_X, 15);
    q = qdd_gate(q, GATEID_Z, 0);           q = qdd_cgate(q, GATEID_X, 0, 15);      q = qdd_gate(q, GATEID_H, 16);          q = qdd_gate(q, GATEID_Z, 8);
    q = qdd_cgate(q, GATEID_X, 12, 14);     q = qdd_cgate(q, GATEID_Z, 2, 18);      q = qdd_cgate(q, GATEID_X, 12, 15);     q = qdd_gate(q, GATEID_X, 9);
    q = qdd_gate(q, GATEID_Z, 12);          q = qdd_gate(q, GATEID_X, 3);           q = qdd_gate(q, GATEID_X, 0);           q = qdd_cgate(q, GATEID_X, 1, 4);
    q = qdd_gate(q, GATEID_H, 1);           q = qdd_gate(q, GATEID_X, 19);          q = qdd_gate(q, GATEID_X, 5);           q = qdd_cgate(q, GATEID_Z, 2, 16);
    q = qdd_gate(q, GATEID_X, 4);           q = qdd_cgate(q, GATEID_X, 9, 11);      q = qdd_cgate(q, GATEID_X, 0, 7);       q = qdd_gate(q, GATEID_Z, 12);
    q = qdd_cgate(q, GATEID_X, 9, 11);      q = qdd_gate(q, GATEID_Z, 13);          q = qdd_cgate(q, GATEID_X, 12, 16);     q = qdd_gate(q, GATEID_Z, 10);
    q = qdd_gate(q, GATEID_X, 4);           q = qdd_gate(q, GATEID_Z, 16);          q = qdd_cgate(q, GATEID_Z, 4, 17);      q = qdd_gate(q, GATEID_Z, 7);
    q = qdd_gate(q, GATEID_H, 4);           q = qdd_cgate(q, GATEID_Z, 6, 7);       q = qdd_cgate(q, GATEID_X, 12, 19);     q = qdd_gate(q, GATEID_Z, 15);
    q = qdd_cgate(q, GATEID_X, 5, 11);      q = qdd_cgate(q, GATEID_X, 9, 17);      q = qdd_gate(q, GATEID_Z, 3);           q = qdd_cgate(q, GATEID_X, 11, 18);
    q = qdd_cgate(q, GATEID_Z, 5, 15);      q = qdd_cgate(q, GATEID_X, 0, 15);      q = qdd_cgate(q, GATEID_X, 1, 6);       q = qdd_cgate(q, GATEID_X, 8, 16);
    q = qdd_cgate(q, GATEID_X, 5, 19);      q = qdd_cgate(q, GATEID_Z, 3, 18);      q = qdd_cgate(q, GATEID_X, 5, 8);       q = qdd_cgate(q, GATEID_Z, 14, 18);
    // inverse
    q = qdd_cgate(q, GATEID_Z, 14, 18);     q = qdd_cgate(q, GATEID_X, 5, 8);       q = qdd_cgate(q, GATEID_Z, 3, 18);      q = qdd_cgate(q, GATEID_X, 5, 19);
    q = qdd_cgate(q, GATEID_X, 8, 16);      q = qdd_cgate(q, GATEID_X, 1, 6);       q = qdd_cgate(q, GATEID_X, 0, 15);      q = qdd_cgate(q, GATEID_Z, 5, 15);
    q = qdd_cgate(q, GATEID_X, 11, 18);     q = qdd_gate(q, GATEID_Z, 3);           q = qdd_cgate(q, GATEID_X, 9, 17);      q = qdd_cgate(q, GATEID_X, 5, 11);
    q = qdd_gate(q, GATEID_Z, 15);          q = qdd_cgate(q, GATEID_X, 12, 19);     q = qdd_cgate(q, GATEID_Z, 6, 7);       q = qdd_gate(q, GATEID_H, 4);
    q = qdd_gate(q, GATEID_Z, 7);           q = qdd_cgate(q, GATEID_Z, 4, 17);      q = qdd_gate(q, GATEID_Z, 16);          q = qdd_gate(q, GATEID_X, 4);
    q = qdd_gate(q, GATEID_Z, 10);          q = qdd_cgate(q, GATEID_X, 12, 16);     q = qdd_gate(q, GATEID_Z, 13);          q = qdd_cgate(q, GATEID_X, 9, 11);
    q = qdd_gate(q, GATEID_Z, 12);          q = qdd_cgate(q, GATEID_X, 0, 7);       q = qdd_cgate(q, GATEID_X, 9, 11);      q = qdd_gate(q, GATEID_X, 4);
    q = qdd_cgate(q, GATEID_Z, 2, 16);      q = qdd_gate(q, GATEID_X, 5);           q = qdd_gate(q, GATEID_X, 19);          q = qdd_gate(q, GATEID_H, 1);
    q = qdd_cgate(q, GATEID_X, 1, 4);       q = qdd_gate(q, GATEID_X, 0);           q = qdd_gate(q, GATEID_X, 3);           q = qdd_gate(q, GATEID_Z, 12);
    q = qdd_gate(q, GATEID_X, 9);           q = qdd_cgate(q, GATEID_X, 12, 15);     q = qdd_cgate(q, GATEID_Z, 2, 18);      q = qdd_cgate(q, GATEID_X, 12, 14);
    q = qdd_gate(q, GATEID_Z, 8);           q = qdd_gate(q, GATEID_H, 16);          q = qdd_cgate(q, GATEID_X, 0, 15);      q = qdd_gate(q, GATEID_Z, 0);
    q = qdd_gate(q, GATEID_X, 15);          q = qdd_gate(q, GATEID_X, 6);           q = qdd_cgate(q, GATEID_Z, 1, 3);       q = qdd_cgate(q, GATEID_X, 13, 19);
    q = qdd_cgate(q, GATEID_Z, 11, 16);     q = qdd_cgate(q, GATEID_Z, 10, 12);     q = qdd_cgate(q, GATEID_X, 8, 9);       q = qdd_cgate(q, GATEID_Z, 2, 19);
    q = qdd_gate(q, GATEID_X, 1);           q = qdd_cgate(q, GATEID_Z, 4, 5);       q = qdd_gate(q, GATEID_Z, 11);          q = qdd_gate(q, GATEID_X, 18);
    q = qdd_gate(q, GATEID_X, 6);           q = qdd_cgate(q, GATEID_X, 9, 10);      q = qdd_gate(q, GATEID_X, 2);           q = qdd_gate(q, GATEID_X, 16);
    q = qdd_cgate(q, GATEID_X, 7, 18);      q = qdd_gate(q, GATEID_Z, 16);          q = qdd_gate(q, GATEID_X, 18);          q = qdd_cgate(q, GATEID_X, 7, 10);
    q = qdd_cgate(q, GATEID_Z, 0, 15);      q = qdd_cgate(q, GATEID_Z, 16, 18);     q = qdd_gate(q, GATEID_X, 15);          q = qdd_cgate(q, GATEID_X, 4, 10);
    q = qdd_gate(q, GATEID_X, 18);          q = qdd_gate(q, GATEID_Z, 4);           q = qdd_gate(q, GATEID_X, 18);          q = qdd_cgate(q, GATEID_X, 12, 16);
    q = qdd_gate(q, GATEID_Z, 11);          q = qdd_gate(q, GATEID_X, 17);          q = qdd_cgate(q, GATEID_X, 7, 18);      q = qdd_gate(q, GATEID_X, 8);
    q = qdd_gate(q, GATEID_X, 9);           q = qdd_gate(q, GATEID_H, 8);           q = qdd_cgate(q, GATEID_Z, 10, 12);     q = qdd_cgate(q, GATEID_Z, 14, 15);
    q = qdd_gate(q, GATEID_Z, 18);          q = qdd_cgate(q, GATEID_X, 5, 19);      q = qdd_cgate(q, GATEID_Z, 11, 16);     q = qdd_cgate(q, GATEID_X, 3, 6);
    q = qdd_gate(q, GATEID_Z, 6);           q = qdd_cgate(q, GATEID_X, 7, 10);      q = qdd_cgate(q, GATEID_X, 2, 15);      q = qdd_cgate(q, GATEID_X, 3, 18);
    q = qdd_cgate(q, GATEID_X, 6, 16);      q = qdd_cgate(q, GATEID_Z, 1, 4);       q = qdd_cgate(q, GATEID_X, 3, 5);       q = qdd_cgate(q, GATEID_Z, 7, 11);
    q = qdd_cgate(q, GATEID_Z, 13, 16);     q = qdd_cgate(q, GATEID_Z, 1, 16);      q = qdd_cgate(q, GATEID_Z, 0, 4);       q = qdd_cgate(q, GATEID_Z, 9, 10);
    q = qdd_gate(q, GATEID_Z, 4);           q = qdd_cgate(q, GATEID_X, 1, 12);      q = qdd_gate(q, GATEID_H, 16);          q = qdd_cgate(q, GATEID_Z, 4, 18);

    test_assert(equivalent(q, qref, 20, false, VERBOSE)); // check approx equiv
    test_assert(equivalent(q, qref, 20, true,  VERBOSE)); // check exact equiv
    test_assert(q == qref);

    if(VERBOSE) printf("qdd 20 qubit circuit: ok\n");
    free_amplitude_table();
    return 0;
}


int runtests()
{
    // we are not testing garbage collection
    sylvan_gc_disable();

    if (test_cmap()) return 1;
    if (test_complex_operations()) return 1;
    if (test_basis_state_creation()) return 1;
    if (test_vector_addition()) return 1;
    if (test_x_gate()) return 1;
    if (test_h_gate()) return 1;
    if (test_phase_gates()) return 1;
    if (test_cx_gate()) return 1;
    if (test_cz_gate()) return 1;
    if (test_10qubit_circuit()) return 1;
    if (test_20qubit_circuit()) return 1;

    return 0;
}

int main()
{
    // Standard Lace initialization with 1 worker
    lace_init(1, 0);
    lace_startup(0, NULL, NULL);

    // Simple Sylvan initialization
    sylvan_set_sizes(1LL<<25, 1LL<<25, 1LL<<16, 1LL<<16);
    sylvan_init_package();
    // we also need init_bdd() because some qdd functions 
    // rely on bdd stuff (like cache)
    sylvan_init_bdd();
    // TODO: make sylvan_init_qdd() function and handle stuff there

    int res = runtests();

    sylvan_quit();
    lace_exit();

    return res;
}
