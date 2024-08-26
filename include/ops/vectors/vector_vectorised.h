#ifndef _VECTOR_SPECIALISED_H
#define _VECTOR_SPECIALISED_H

#ifndef _VOPS_FILE
#error "vector_vectorised.h must be only be included by vops.h"
#endif


#include "../../intrinsics.h"
#include "../../vectors/vector.h"
#include "../selectors/op_selector.h"
#include "generic_ops.h"

#include "utils.h"

namespace arc::detail {

    // Helper defines
    #define VTYPE vec<_Dim, _Type>
    #define VOPS_FN_CP1(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline VTYPE vOps<_Storage>::name(const VTYPE& A, const VTYPE& B)
    #define VOPS_FN_CP2(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline VTYPE vOps<_Storage>::name(const VTYPE& A, const _Type S)
    #define VOPS_FN_MUT1(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline void vOps<_Storage>::name(VTYPE& A, const VTYPE& B)
    #define VOPS_FN_MUT2(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline void vOps<_Storage>::name(VTYPE& A, const _Type S)
    #define VOPS_FN_REP(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline VTYPE vOps<_Storage>::name(const VTYPE& A, const _Type S)
    #define VOPS_FN_CMP1(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline bool vOps<_Storage>::name(const VTYPE& A, const VTYPE& B)
    #define VOPS_FN_CMP2(name) template<typename _Storage> template<int _Dim, typename _Type> OOL_STATIC constexpr inline bool vOps<_Storage>::name(const VTYPE& A, const _Type S)
    #define TO_VEC(val) op_selector<_Storage, _Dim>::set1(val)



    /* vOps Implementations */

    // Addition
    VOPS_FN_CP1(vec_add) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_add(A, B);
        else
            o.wide = op_selector<_Storage, _Dim>::add(A.wide, B.wide);
        return o;
    }
    VOPS_FN_CP2(vec_add) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_add(A, S);
        else
            o.wide = op_selector<_Storage, _Dim>::add(A.wide, TO_VEC(S));
        return o;
    }
    VOPS_FN_MUT1(vec_add_mut) {
        if (is_comptime::evaluate())
            generic_vec_add_mut(A, B);
        else
            A.wide = op_selector<_Storage, _Dim>::add(A.wide, B.wide);
    }
    VOPS_FN_MUT2(vec_add_mut) {
        if (is_comptime::evaluate())
            generic_vec_add_mut(A, S);
        else
            A.wide = op_selector<_Storage, _Dim>::add(A.wide, TO_VEC(S));
    }


    // Subtraction
    VOPS_FN_CP1(vec_sub) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_sub(A, B);
        else
            o.wide = op_selector<_Storage, _Dim>::sub(A.wide, B.wide);
        return o;
    }
    VOPS_FN_CP2(vec_sub) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_sub(A, S);
        else
            o.wide = op_selector<_Storage, _Dim>::sub(A.wide, TO_VEC(S));
        return o;
    }
    VOPS_FN_MUT1(vec_sub_mut) {
        if (is_comptime::evaluate())
            generic_vec_sub_mut(A, B);
        else
            A.wide = op_selector<_Storage, _Dim>::sub(A.wide, B.wide);
    }
    VOPS_FN_MUT2(vec_sub_mut) {
        if (is_comptime::evaluate())
            generic_vec_sub_mut(A, S);
        else
            A.wide = op_selector<_Storage, _Dim>::sub(A.wide, TO_VEC(S));
    }
    VOPS_FN_REP(vec_sub_recip) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_sub_recip(A, S);
        else
            o.wide = op_selector<_Storage, _Dim>::sub(TO_VEC(S), A.wide);
        return o;
    }


    // Multiplication
    VOPS_FN_CP1(vec_mul) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_mul(A, B);
        else
            o.wide = op_selector<_Storage, _Dim>::mul(A.wide, B.wide);
        return o;
    }
    VOPS_FN_CP2(vec_mul) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_mul(A, S);
        else
            o.wide = op_selector<_Storage, _Dim>::mul(A.wide, TO_VEC(S));
        return o;
    }
    VOPS_FN_MUT1(vec_mul_mut) {
        if (is_comptime::evaluate())
            generic_vec_mul_mut(A, B);
        else
            A.wide = op_selector<_Storage, _Dim>::mul(A.wide, B.wide);
    }
    VOPS_FN_MUT2(vec_mul_mut) {
        if (is_comptime::evaluate())
            generic_vec_mul_mut(A, S);
        else
            A.wide = op_selector<_Storage, _Dim>::mul(A.wide, TO_VEC(S));
    }



    // Division
    VOPS_FN_CP1(vec_div) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_div(A, B);
        else
            o.wide = op_selector<_Storage, _Dim>::div(A.wide, B.wide);
        return o;
    }
    VOPS_FN_CP2(vec_div) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_div(A, S);
        else
            o.wide = op_selector<_Storage, _Dim>::div(A.wide, TO_VEC(S));
    }
    VOPS_FN_MUT1(vec_div_mut) {
        if (is_comptime::evaluate())
            generic_vec_div_mut(A, B);
        else
            A.wide = op_selector<_Storage, _Dim>::div(A.wide, B.wide);
    }
    VOPS_FN_MUT2(vec_div_mut) {
        if (is_comptime::evaluate())
            generic_vec_div_mut(A, S);
        else
            A.wide = op_selector<_Storage, _Dim>::div(A.wide, TO_VEC(S));
    }
    VOPS_FN_REP(vec_div_recip) {
        VTYPE o;
        if (is_comptime::evaluate())
            o = generic_vec_div_recip(A, S);
        else
            o.wide = op_selector<_Storage, _Dim>::div(TO_VEC(S), A.wide);
        return o;
    }


    // Equality operator
    VOPS_FN_CMP1(vec_eq) {
        if (is_comptime::evaluate())
            return generic_vec_eq(A, B);
        else
            return op_selector<_Storage, _Dim>::eq(A.wide, B.wide);
    }
    VOPS_FN_CMP2(vec_eq) {
        if (is_comptime::evaluate())
            return generic_vec_eq(A, S);
        else
            return op_selector<_Storage, _Dim>::eq(A.wide, TO_SCALAR(S));
    }


    // Undefs just to be safe
    #undef VTYPE
    #undef VOPS_FN_CP1
    #undef VOPS_FN_CP2
    #undef VOPS_FN_MUT1
    #undef VOPS_FN_MUT2
    #undef VOPS_FN_REP
    #undef VOPS_FN_CMP1
    #undef VOPS_FN_CMP2
}

#endif // _VECTOR_SPECIALISED_H
