#ifndef _VECTOR_GENERIC_OPS_H
#define _VECTOR_GENERIC_OPS_H

#include "../../vectors/vector.h"

namespace arc::detail {

    // Helper defines
    #define VTYPE vec<_Dim, _Type>
    #define VOPS_FN_CP1(name) template<int _Dim, typename _Type> static constexpr inline VTYPE name(const VTYPE& A, const VTYPE& B)
    #define VOPS_FN_CP2(name) template<int _Dim, typename _Type> static constexpr inline VTYPE name(const VTYPE& A, const _Type S)
    #define VOPS_FN_MUT1(name) template<int _Dim, typename _Type> static constexpr inline void name(VTYPE& A, const VTYPE& B)
    #define VOPS_FN_MUT2(name) template<int _Dim, typename _Type> static constexpr inline void name(VTYPE& A, const _Type S)
    #define VOPS_FN_REP(name) template<int _Dim, typename _Type> static constexpr inline VTYPE name(const VTYPE& A, const _Type S)
    #define VOPS_FN_CMP1(name) template<int _Dim, typename _Type> static constexpr inline bool name(const VTYPE& A, const VTYPE& B)
    #define VOPS_FN_CMP2(name) template<int _Dim, typename _Type> static constexpr inline bool name(const VTYPE& A, const _Type S)

    #define LOOP1(op) int i = _Dim - 1; do { o.arr[i] = A.arr[i] op B.arr[i]; --i; } while (i >= 0);
    #define LOOP2(op) int i = _Dim - 1; do { o.arr[i] = A.arr[i] op S; --i; } while (i >= 0);
    #define LOOP_MUT1(op) int i = _Dim - 1; do { A.arr[i] = A.arr[i] op B.arr[i]; --i; } while (i >= 0);
    #define LOOP_MUT2(op) int i = _Dim - 1; do { A.arr[i] = A.arr[i] op S; --i; } while (i >= 0);

    /* Implemenations */

    // Addition
    VOPS_FN_CP1(generic_vec_add) {
        VTYPE o;
        LOOP1(+)
        return o;
    }
    VOPS_FN_CP2(generic_vec_add) {
        VTYPE o;
        LOOP2(+)
        return o;
    }
    VOPS_FN_MUT1(generic_vec_add_mut) {
        LOOP_MUT1(+)
    }
    VOPS_FN_MUT2(generic_vec_add_mut) {
        LOOP_MUT2(+)
    }


    // Subtraction
    VOPS_FN_CP1(generic_vec_sub) {
        VTYPE o;
        LOOP1(-)
        return o;
    }
    VOPS_FN_CP2(generic_vec_sub) {
        VTYPE o;
        LOOP2(-)
        return o;
    }
    VOPS_FN_MUT1(generic_vec_sub_mut) {
        LOOP_MUT1(-)
    }
    VOPS_FN_MUT2(generic_vec_sub_mut) {
        LOOP_MUT2(-)
    }
    VOPS_FN_REP(generic_vec_sub_recip) {
        int i = _Dim - 1;
        VTYPE o;
        do {
            o.arr[i] = S - A.arr[i];
            --i;
        } while (i >= 0);
        return o;
    }


    // Multiplication
    VOPS_FN_CP1(generic_vec_mul) {
        VTYPE o;
        LOOP1(*)
        return o;
    }
    VOPS_FN_CP2(generic_vec_mul) {
        VTYPE o;
        LOOP2(*)
        return o;
    }
    VOPS_FN_MUT1(generic_vec_mul_mut) {
        LOOP_MUT1(*)
    }
    VOPS_FN_MUT2(generic_vec_mul_mut) {
        LOOP_MUT2(*)
    }


    // Division
    VOPS_FN_CP1(generic_vec_div) {
        VTYPE o;
        LOOP1(/)
        return o;
    }
    VOPS_FN_CP2(generic_vec_div) {
        VTYPE o;
        LOOP2(/)
        return o;
    }
    VOPS_FN_MUT1(generic_vec_div_mut) {
        LOOP_MUT1(/)
    }
    VOPS_FN_MUT2(generic_vec_div_mut) {
        LOOP_MUT2(/)
    }
    VOPS_FN_REP(generic_vec_div_recip) {
        VTYPE o;
        int i = _Dim - 1;
        do {
            o.arr[i] = S / A.arr[i];
            --i;
        } while (i >= 0);
        return o;
    }


    // Equality Operator
    VOPS_FN_CMP1(generic_vec_eq) {
        int i = _Dim - 1;
        bool o = true;
        do {
            o &= A.arr[i] == B.arr[i];
            --i;
        } while (i >= 0 && o);
        return o;
    }
    VOPS_FN_CMP2(generic_vec_eq) {
        int i = _Dim - 1;
        bool o = true;
        do {
            o &= A.arr[i] == S;
            --i;
        } while (i >= 0 && o);
        return o;
    }


    // Undefs to be safe
    #undef VTYPE
    #undef VOPS_FN_CP1
    #undef VOPS_FN_CP2
    #undef VOPS_FN_MUT1
    #undef VOPS_FN_MUT2
    #undef VOPS_FN_REP
    #undef VOPS_FN_CMP1
    #undef VOPS_FN_CMP2
    #undef LOOP1
    #undef LOOP2
    #undef LOOP_MUT1
    #undef LOOP_MUT2

}


#endif // _VECTOR_GENERIC_OPS_H
