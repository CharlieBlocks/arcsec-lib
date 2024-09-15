#ifndef _MATRIX_OPS_H
#define _MATRIX_OPS_H

#include "matrices/matrix.h"

namespace arc::detail {

    #define MTYPE mat<_Rows, _Cols, _Type>

    template<typename _Accelerator>
    struct mOps {

        // Addition
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_add(const MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_add(const MTYPE& mat_a, const _Type scalar);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_add_mut(MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_add_mut(MTYPE& mat_a, const _Type scalar);

        // Subtraction
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_sub(const MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_sub(const MTYPE& mat_a, const _Type scalar);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_sub_mut(MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_sub_mut(MTYPE& mat_a, const _Type scalar);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_sub_recip(const MTYPE& mat_a, const _Type scalar);

        // Multiplication
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_mul(const MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_mul(const MTYPE& mat_a, const _Type scalar);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_mul_mut(MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_mul_mut(MTYPE& mat_a, const _Type scalar);


        // Division
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_div(const MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_div(const MTYPE& mat_a, const _Type scalar);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_div_mut(MTYPE& mat_a, const MTYPE& mat_b);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline void mat_div_mut(MTYPE& mat_a, const _Type scalar);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline MTYPE mat_div_recip(const MTYPE& mat_a, const _Type scalar);


        // Equality operator
        template<int _Rows, int _Cols, typename _Type> static constexpr inline bool mat_eq(const MTYPE &A, const MTYPE &B);
        template<int _Rows, int _Cols, typename _Type> static constexpr inline bool mat_eq(const MTYPE &A, const _Type B);
    };
}


/* Include Specialisations */
#define _MOPS_FILE

// Vectorised specialisations
#include "matrices/matrix_vectorised.h"

// Generic implementations
#include "matrices/matrix_generic.h"

#undef _MOPS_FILE

#endif // _MATRIX_OPS_H
