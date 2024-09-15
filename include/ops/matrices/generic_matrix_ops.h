#ifndef _MATRIX_GENERIC_OPS_H
#define _MATRIX_GENERIC_OPS_H

#include "../../matrices/matrix.h"

namespace arc::detail {

    // Helper deifnes
    #define MTYPE mat<_Rows, _Cols, _Type>
    #define MOPS_FN_MM_M(name) template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE name(const MTYPE& A, const MTYPE& B)
    #define MOPS_FN_MS_M(name) template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE name(const MTYPE& A, const _Type B)
    #define MOPS_FN_MM_M_MUT(name) template<int _Rows, int _Cols, typename _Type> static constexpr inline void name(MTYPE& A, const MTYPE& B)
    #define MOPS_FN_MS_M_MUT(name) template<int _Rows, int _Cols, typename _Type> static constexpr inline void name(MTYPE& A, const _Type B)
    #define MOPS_FN_MM_CMP(name) template<int _Rows, int _Cols, typename _Type> static constexpr inline bool name(const MTYPE &A, const MTYPE &B)
    #define MOPS_FN_MS_CMP(name) template<int _Rows, int _Cols, typename _Type> static constexpr inline bool name(const MTYPE &A, const _Type B)

    #define LOOP1(out, op) \
    int i = _Rows - 1; int j = 0; int k = 0; \
    do { \
        j = _Cols - 1; \
        k = i*MTYPE::HCap + (_Cols - 1); \
        do { \
            out.arr[k] = A.arr[k] op B.arr[k]; \
            --k; \
        } while(--j >= 0); \
    } while (--i >= 0);

    #define LOOP2(out, op) \
    int i = _Rows - 1; int j = 0; int k = _Rows*_Cols - 1; \
    do { \
        j = _Cols - 1; \
        k = i*MTYPE::HCap + (_Cols - 1); \
        do { \
            out.arr[k] = A.arr[k] op B; \
            --k; \
        } while(--j >= 0); \
    } while (--i >= 0);

    #define LOOP3(out, op) \
    int i = _Rows - 1; int j = 0; int k = _Rows*_Cols - 1; \
    do { \
        j = _Cols - 1; \
        k = i*MTYPE::HCap + (_Cols - 1); \
        do { \
            out.arr[k] = B op A.arr[i]; \
            --k; \
        } while(--j >= 0); \
    } while (--i >= 0);

    // #define LOOP1(out, op) int i = _Rows*_Cols - 1; do { out.arr[i] = A.arr[i] op B.arr[i]; --i; } while (i >= 0);
    // #define LOOP2(out, op) int i = _Rows*_Cols - 1; do { out.arr[i] = A.arr[i] op B; --i; } while (i >= 0);
    // #define LOOP3(out, op) int i = _Rows*_Cols - 1; do { out.arr[i] = B op A.arr[i]; --i; } while (i >= 0);

    /* Implementations */

    // Addition
    MOPS_FN_MM_M(generic_mat_add) {
        MTYPE o;
        LOOP1(o, +)
        return o;
    }
    MOPS_FN_MS_M(generic_mat_add) {
        MTYPE o;
        LOOP2(o, +)
        return o;
    }
    MOPS_FN_MM_M_MUT(generic_mat_add_mut) {
        LOOP1(A, +)
    }
    MOPS_FN_MS_M_MUT(generic_mat_add_mut) {
        LOOP2(A, +)
    }


    // Subtraction
    MOPS_FN_MM_M(generic_mat_sub) {
        MTYPE o;
        LOOP1(o, -)
        return o;
    }
    MOPS_FN_MS_M(generic_mat_sub) {
        MTYPE o;
        LOOP2(o, -)
        return o;
    }
    MOPS_FN_MM_M_MUT(generic_mat_sub_mut) {
        LOOP1(A, -)
    }
    MOPS_FN_MS_M_MUT(generic_mat_sub_mut) {
        LOOP2(A, -)
    }
    MOPS_FN_MS_M(generic_mat_sub_recip) {
        MTYPE o;
        LOOP3(o, -)
        return o;
    }


    // Multiplication
    MOPS_FN_MM_M(generic_mat_mul) {
        MTYPE o;
        LOOP1(o,  *);
        return o;
    }
    MOPS_FN_MS_M(generic_mat_mul) {
        MTYPE o;
        LOOP2(o, *)
        return o;
    }
    MOPS_FN_MM_M_MUT(generic_mat_mul_mut) {
        LOOP1(A, *);
    }
    MOPS_FN_MS_M_MUT(generic_mat_mul_mut) {
        LOOP2(A, *);
    }


    //Division
    MOPS_FN_MM_M(generic_mat_div) {
        MTYPE o;
        LOOP1(o, /)
        return o;
    }
    MOPS_FN_MS_M(generic_mat_div) {
        MTYPE o;
        LOOP2(o, /)
        return o;
    }
    MOPS_FN_MM_M_MUT(generic_mat_div_mut) {
        LOOP1(A, /)
    }
    MOPS_FN_MS_M_MUT(generic_mat_div_mut) {
        LOOP2(A, /)
    }
    MOPS_FN_MS_M(generic_mat_div_recip) {
        MTYPE o;
        LOOP3(o, /)
        return o;
    }


    // Equality
    MOPS_FN_MM_CMP(generic_mat_eq) {
        bool o = true;
        int i = _Rows - 1; int j = 0; int k = 0;
        do {
            j = _Cols - 1;
            k = i*MTYPE::HCap + (_Cols - 1);
            do {
                o &= A.arr[k] == B.arr[k];
                --k;
            } while (--j >= 0);
        } while (--i >= 0);

        return o;
    }
    MOPS_FN_MS_CMP(gerneic_mat_eq) {
        bool o = true;
        int i = _Rows - 1; int j = 0; int k = 0;
        do {
            j = _Cols - 1;
            k = i*MTYPE::HCap + (_Cols - 1);
            do {
                o &= A.arr[k] == B;
                --k;
            } while (--j >= 0);
        } while (--i >= 0);
        return o;
    }


    // Cleanup
    #undef MTYPE
    #undef MOPS_FN_MM_M
    #undef MOPS_FN_MS_M
    #undef MOPS_FN_MM_M_MUT
    #undef MOPS_FN_MS_M_MUT
    #undef MOPS_FN_MM_CMP
    #undef MOPS_FN_MS_CMP

}

#endif // _MATRIX_GENERIC_OPS_H
