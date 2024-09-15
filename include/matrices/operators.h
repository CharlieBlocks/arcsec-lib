#ifndef _ARC_MAT_OPERATORS_H
#define _ARC_MAT_OPERATORS_H


#include "matrix.h"
#include "../intrinsics.h"
#include "../ops/mops.h"

namespace arc {

    // Arithmetric operator overloads
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator +(const mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_add(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator +(const mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_add(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator -(const mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_sub(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator -(const mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_sub(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator *(const mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_mul(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator *(const mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_mul(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator /(const mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_div(A, B); };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator /(const mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_div(A, B); };


    // Inplace arithmetic operators
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator +=(mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_add_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator +=(mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_add_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator -=(mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_sub_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator -=(mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_sub_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator *=(mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_mul_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator *=(mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_mul_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator /=(mat<_Rows, _Cols, _Storage>& A, const mat<_Rows, _Cols, _Storage>& B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_div_mut(A, B); return A; };
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> &operator /=(mat<_Rows, _Cols, _Storage>& A, const _Storage B) noexcept { detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_div_mut(A, B); return A; };


    // Equality operators
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline bool operator ==(const mat<_Rows, _Cols, _Storage> &A, const mat<_Rows, _Cols, _Storage> &B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_eq(A, B); }
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline bool operator ==(const mat<_Rows, _Cols, _Storage> &A, const _Storage B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_eq(A, B); }


    // Reciprocal operators
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator +(const _Storage A, const mat<_Rows, _Cols, _Storage> &B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_add(B, A); }
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator -(const _Storage A, const mat<_Rows, _Cols, _Storage> &B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_sub_recip(B, A); }
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator *(const _Storage A, const mat<_Rows, _Cols, _Storage> &B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_mul(B, A); }
    template<int _Rows, int _Cols, typename _Storage>
    static constexpr inline mat<_Rows, _Cols, _Storage> operator /(const _Storage A, const mat<_Rows, _Cols, _Storage> &B) noexcept { return detail::mOps<typename type_selector<_Cols, _Storage>::type>::mat_div_recip(B, A); }

}



#endif // _ARC_MAT_OPERATORS_H
