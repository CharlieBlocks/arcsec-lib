#ifndef _VECTOR_GENERIC_H
#define _VECTOR_GENERIC_H

#ifndef _VOPS_FILE
#error "vector_generic.h should only be included by vops.h"
#endif

#include "../../intrinsics.h"
#include "../../vectors/vector.h"
#include "vector_vectorised.h"
#include "generic_ops.h"
#include "utils.h"

namespace arc::detail {

    #define VTYPE vec<_Dim, _Type>
    #define GENERIC_FUNC1(ret, name, fn) template<int _Dim, typename _Type> OOL_STATIC constexpr inline ret vOps<void*>::name(const VTYPE& A, const VTYPE& B) {return fn(A, B);}
    #define GENERIC_FUNC2(ret, name, fn) template<int _Dim, typename _Type> OOL_STATIC constexpr inline ret vOps<void*>::name(const VTYPE& A, const _Type S) { return fn(A, S);}
    #define GENERIC_FUNC3(ret, name, fn) template<int _Dim, typename _Type> OOL_STATIC constexpr inline ret vOps<void*>::name(VTYPE& A, const VTYPE& B) { return fn(A, B);}
    #define GENERIC_FUNC4(ret, name, fn) template<int _Dim, typename _Type> OOL_STATIC constexpr inline ret vOps<void*>::name(VTYPE& A, const _Type S) { return fn(A, S);}

    template<>
    struct vOps<void*> {
        // Addition
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_add(const VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_add(const VTYPE& A, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_add_mut(VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline void vec_add_mut(VTYPE& A, const _Type scalar);

        // Subtraction
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_sub(const VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_sub(const VTYPE& A, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_sub_mut(VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline void vec_sub_mut(VTYPE& A, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_sub_recip(const VTYPE& A, const _Type B);

        // Multiplication
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_mul(const VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_mul(const VTYPE& A, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_mul_mut(VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline void vec_mul_mut(VTYPE& A, const _Type scalar);

        // Division
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_div(const VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_div(const VTYPE& A, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_div_mut(VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline void vec_div_mut(VTYPE& A, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_div_recip(const VTYPE& A, const _Type B);

        // Equality
        template<int _Dim, typename _Type> static constexpr inline bool vec_eq(const VTYPE& A, const VTYPE& B);
        template<int _Dim, typename _Type> static constexpr inline bool vec_eq(const VTYPE& A, const _Type scalar);
    };


    // Addition implementation
    GENERIC_FUNC1(VTYPE, vec_add, generic_vec_add)
    GENERIC_FUNC2(VTYPE, vec_add, generic_vec_add)
    GENERIC_FUNC3(void, vec_add_mut, generic_vec_add_mut)
    GENERIC_FUNC4(void, vec_add_mut, generic_vec_add_mut)

    // Subtraction implementation
    GENERIC_FUNC1(VTYPE, vec_sub, generic_vec_sub)
    GENERIC_FUNC2(VTYPE, vec_sub, generic_vec_sub)
    GENERIC_FUNC3(void, vec_sub_mut, generic_vec_sub_mut)
    GENERIC_FUNC4(void, vec_sub_mut, generic_vec_sub_mut)
    GENERIC_FUNC2(VTYPE, vec_sub_recip, generic_vec_sub_recip)

    // Multiplication Implementation
    GENERIC_FUNC1(VTYPE, vec_mul, generic_vec_mul)
    GENERIC_FUNC2(VTYPE, vec_mul, generic_vec_mul)
    GENERIC_FUNC3(void, vec_mul_mut, generic_vec_mul_mut)
    GENERIC_FUNC4(void, vec_mul_mut, generic_vec_mul_mut)

    // Division Implementation
    GENERIC_FUNC1(VTYPE, vec_div, generic_vec_div)
    GENERIC_FUNC2(VTYPE, vec_div, generic_vec_div)
    GENERIC_FUNC3(void, vec_div_mut, generic_vec_div_mut)
    GENERIC_FUNC4(void, vec_div_mut, generic_vec_div_mut)
    GENERIC_FUNC2(VTYPE, vec_div_recip, generic_vec_sub_recip)

    // Equality Implementation
    GENERIC_FUNC1(bool, vec_eq, generic_vec_eq)
    GENERIC_FUNC2(bool, vec_eq, generic_vec_eq)


    // Undefs
    #undef VTYPe
    #undef GENERIC_FUNC1
    #undef GENERIC_FUNC2
    #undef GENERIC_FUNC3
    #undef GENERIC_FUNC4
}


#endif // _VECTOR_GENERIC_H
