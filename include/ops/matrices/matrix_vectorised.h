#ifndef _MATRIX_VECTORISED_H
#define _MATRIX_VECTORISED_H

#ifndef _MOPS_FILE
#error "matrix_vectorised.h must only be included by mops.h"
#endif

#include "intrinsics.h"
#include "matrices/matrix.h"
#include "../selectors/op_selector.h"
#include "generic_matrix_ops.h"
#include "utils.h"


namespace arc::detail {


    /* Helper defines */
    #define MTYPE mat<_Rows, _Cols, _Type>

    #define MOPS_FN_MM_M(name) template<typename _Storage> template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline MTYPE mOps<_Storage>::name(const MTYPE &A, const MTYPE &B)
    #define MOPS_FN_MS_M(name) template<typename _Storage> template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline MTYPE mOps<_Storage>::name(const MTYPE &A, const _Type B)
    #define MOPS_FN_MM_M_MUT(name) template<typename _Storage> template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline void mOps<_Storage>::name(MTYPE &A, const MTYPE &B)
    #define MOPS_FN_MS_M_MUT(name) template<typename _Storage> template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline void mOps<_Storage>::name(MTYPE &A, const _Type B)
    #define MOPS_FN_MM_CMP(name) template<typename _Storage> template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline bool mOps<_Storage>::name(const MTYPE &A, const MTYPE &B)
    #define MOPS_FN_MS_CMP(name) template<typename _Storage> template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline bool mOps<_Storage>::name(const MTYPE &A, const _Type B)

    #define TO_VEC(val) op_selector<_Storage, _Cols>::set1(val)


    /* Implementations */

    // Addition
    MOPS_FN_MM_M(mat_add) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_add(A, B);
        else {
            // We are assuming that the compiler will unroll small loops
            // We could use template inlining to force inline code but that would
            // Make unceassarcy binary sizes for large, accelerated matrix operations
            int i = _Rows - 1;
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::add(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MS_M(mat_add) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_add(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::add(A.wide[i], v);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MM_M_MUT(mat_add_mut) {
        if (is_comptime::evaluate())
            generic_mat_add_mut(A, B);
        else {
            int i = _Rows - 1;
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::add(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }
    }
    MOPS_FN_MS_M_MUT(mat_add_mut) {
        if (is_comptime::evaluate())
            generic_mat_add_mut(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::add(A.wide[i], v);
            } while(--i >= 0);
        }
    }



    // Subtraction
    MOPS_FN_MM_M(mat_sub) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_sub(A, B);
        else {
            int i = _Rows - 1;
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::sub(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MS_M(mat_sub) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_sub(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::sub(A.wide[i], v);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MM_M_MUT(mat_sub_mut) {
        if (is_comptime::evaluate())
            generic_mat_sub_mut(A, B);
        else {
            int i = _Rows - 1;
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::sub(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }
    }
    MOPS_FN_MS_M_MUT(mat_sub_mut) {
        if (is_comptime::evaluate())
            generic_mat_sub_mut(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::sub(A.wide[i], v);
            } while(--i >= 0);
        }
    }
    MOPS_FN_MS_M(mat_sub_recip) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_sub_recip(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::sub(v, A.wide[i]);
            } while (--i >= 0);
        }
        return o;
    }



    // Multiplication
    MOPS_FN_MM_M(mat_mul) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_mul(A, B);
        else {
            int i = _Rows - 1;
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::mul(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MS_M(mat_mul) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_mul(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::mul(A.wide[i], v);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MM_M_MUT(mat_mul_mut) {
        if (is_comptime::evaluate())
            generic_mat_mul_mut(A, B);
        else {
            int i = _Rows - 1;
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::mul(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }
    }
    MOPS_FN_MS_M_MUT(mat_mul_mut) {
        if (is_comptime::evaluate())
            generic_mat_mul_mut(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::mul(A.wide[i], v);
            } while(--i >= 0);
        }
    }



    // Division
    MOPS_FN_MM_M(mat_div) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_div(A, B);
        else {
            int i = _Rows - 1;
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::div(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MS_M(mat_div) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_div(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::div(A.wide[i], v);
            } while(--i >= 0);
        }

        return o;
    }
    MOPS_FN_MM_M_MUT(mat_div_mut) {
        if (is_comptime::evaluate())
            generic_mat_div_mut(A, B);
        else {
            int i = _Rows - 1;
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::div(A.wide[i], B.wide[i]);
            } while(--i >= 0);
        }
    }
    MOPS_FN_MS_M_MUT(mat_div_mut) {
        if (is_comptime::evaluate())
            generic_mat_div_mut(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                A.wide[i] = op_selector<_Storage, _Cols>::div(A.wide[i], v);
            } while(--i >= 0);
        }
    }
    MOPS_FN_MS_M(mat_div_recip) {
        MTYPE o;
        if (is_comptime::evaluate())
            o = generic_mat_div_recip(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                o.wide[i] = op_selector<_Storage, _Cols>::div(v, A.wide[i]);
            } while(--i >= 0);
        }

        return o;
    }


    // Equality operators
    MOPS_FN_MM_CMP(mat_eq) {
        bool out = true;
        if (is_comptime::evaluate())
            out = generic_mat_eq(A, B);
        else {
            int i = _Rows - 1;
            do {
                out &= op_selector<_Storage, _Cols>::eq(A.wide[i], B.wide[i]);
            } while (--i >= 0);
        }
        return out;
    }
    MOPS_FN_MS_CMP(mat_eq) {
        bool out = true;
        if (is_comptime::evaluate())
            out = generic_mat_eq(A, B);
        else {
            int i = _Rows - 1;
            auto v = TO_VEC(B);
            do {
                out &= op_selector<_Storage, _Cols>::eq(A.wide[i], v);
            } while (--i >= 0);
        }
        return out;
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


#endif // _MATRIX_VECTORISED_H
