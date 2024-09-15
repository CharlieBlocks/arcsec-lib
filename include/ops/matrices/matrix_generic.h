#ifndef _MATRIX_GENERIC_H
#define _MATRIX_GENERIC_H

#ifndef _MOPS_FILE
#error "matrix_generic.h should only be included in mops.h"
#endif

#include "../../intrinsics.h"
#include "../../matrices/matrix.h"
#include "generic_matrix_ops.h"
//#include "matrix_vectorised.h"
#include "utils.h"



namespace arc::detail {

    template<typename _Accelerator>
    struct mOps;

    /* Helper defines */
    #define MTYPE mat<_Rows, _Cols, _Type>
    #define GENERIC_DEF1(ret, name)         template<int _Rows, int _Cols, typename _Type> static constexpr inline ret name(const MTYPE& A, const MTYPE& B) noexcept;
    #define GENERIC_DEF2(ret, name)         template<int _Rows, int _Cols, typename _Type> static constexpr inline ret name(const MTYPE& A, const _Type B) noexcept;
    #define GENERIC_DEF3(name)         template<int _Rows, int _Cols, typename _Type> static constexpr inline void name(MTYPE& A, const MTYPE& B) noexcept;
    #define GENERIC_DEF4(name)         template<int _Rows, int _Cols, typename _Type> static constexpr inline void name(MTYPE& A, const _Type B) noexcept;

    #define GENERIC_FUNC1(ret, name, fn)    template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline ret mOps<void*>::name(const MTYPE& A, const MTYPE& B) noexcept { return fn(A, B); }
    #define GENERIC_FUNC2(ret, name, fn)    template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline ret mOps<void*>::name(const MTYPE& A, const _Type B) noexcept { return  fn(A, B); }
    #define GENERIC_FUNC3(name, fn)    template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline void mOps<void*>::name(MTYPE& A, const MTYPE& B) noexcept { fn(A, B); }
    #define GENERIC_FUNC4(name, fn)    template<int _Rows, int _Cols, typename _Type> OOL_STATIC constexpr inline void mOps<void*>::name(MTYPE& A, const _Type B) noexcept { fn(A, B); }


    /* mOps specialisation */
    template<>
    struct mOps<void*> {

        // Addition
        GENERIC_DEF1(MTYPE, mat_add)
        GENERIC_DEF2(MTYPE, mat_add)
        GENERIC_DEF3(mat_add_mut)
        GENERIC_DEF4(mat_add_mut)

        // Subtraction
        GENERIC_DEF1(MTYPE, mat_sub)
        GENERIC_DEF2(MTYPE, mat_sub)
        GENERIC_DEF3(mat_sub_mut)
        GENERIC_DEF4(mat_sub_mut)
        GENERIC_DEF2(MTYPE, mat_sub_recip)

        // Multiplication
        GENERIC_DEF1(MTYPE, mat_mul)
        GENERIC_DEF2(MTYPE, mat_mul)
        GENERIC_DEF3(mat_mul_mut)
        GENERIC_DEF4(mat_mul_mut)

        // Division
        GENERIC_DEF1(MTYPE, mat_div)
        GENERIC_DEF2(MTYPE, mat_div)
        GENERIC_DEF3(mat_div_mut)
        GENERIC_DEF4(mat_div_mut)
        GENERIC_DEF2(MTYPE, mat_div_recip)

        GENERIC_DEF1(bool, mat_eq)
        GENERIC_DEF2(bool, mat_eq)
    };


    // Addition Implementation
    GENERIC_FUNC1(MTYPE, mat_add, generic_mat_add)
    GENERIC_FUNC2(MTYPE, mat_add, generic_mat_add)
    GENERIC_FUNC3(mat_add_mut, generic_mat_add_mut)
    GENERIC_FUNC4(mat_add_mut, generic_mat_add_mut)

    // Subtraction Implementation
    GENERIC_FUNC1(MTYPE, mat_sub, generic_mat_sub)
    GENERIC_FUNC2(MTYPE, mat_sub, generic_mat_sub)
    GENERIC_FUNC3(mat_sub_mut, generic_mat_sub_mut)
    GENERIC_FUNC4(mat_sub_mut, generic_mat_sub_mut)
    GENERIC_FUNC2(MTYPE, mat_sub_recip, generic_mat_sub_recip)

    // Multiplication Implementation
    GENERIC_FUNC1(MTYPE, mat_mul, generic_mat_mul)
    GENERIC_FUNC2(MTYPE, mat_mul, generic_mat_mul)
    GENERIC_FUNC3(mat_mul_mut, generic_mat_mul_mut)
    GENERIC_FUNC4(mat_mul_mut, generic_mat_mul_mut)

    // Division Implementation
    GENERIC_FUNC1(MTYPE, mat_div, generic_mat_div)
    GENERIC_FUNC2(MTYPE, mat_div, generic_mat_div)
    GENERIC_FUNC3(mat_div_mut, generic_mat_div_mut)
    GENERIC_FUNC4(mat_div_mut, generic_mat_div_mut)
    GENERIC_FUNC2(MTYPE, mat_div_recip, generic_mat_div_recip)

    // Equality Implementation
    GENERIC_FUNC1(bool, mat_eq, generic_mat_eq)
    GENERIC_FUNC2(bool, mat_eq, generic_mat_eq)


    // Cleanup
    #undef MTYPE
    #undef GENERIC_DEF1
    #undef GENERIC_DEF2
    #undef GENERIC_DEF3
    #undef GENERIC_DEF4
    #undef GENERIC_FUNC1
    #undef GENERIC_FUNC2
    #undef GENERIC_FUNC3
    #undef GENERIC_FUNC4

}

#endif // _MATRIX_GENERIC_H
