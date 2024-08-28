#ifndef _ARC_VECTOR_OPERATORS_H
#define _ARC_VECTOR_OPERATORS_H

#include "vector.h"
#include "../intrinsics.h"
#include "../ops/vops.h"

namespace arc {

    // Arithmetic Operator overloads
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator +(const vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_add(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator -(const vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_sub(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator *(const vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_mul(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator /(const vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_div(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator +(const vec<_Dim, _Storage>& A, const _Storage B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_add(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator -(const vec<_Dim, _Storage>& A, const _Storage B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_sub(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator *(const vec<_Dim, _Storage>& A, const _Storage B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_mul(A, B); }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator /(const vec<_Dim, _Storage>& A, const _Storage B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_div(A, B); }


    // Inplace operators overloads
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator +=(vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_add_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator -=(vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_sub_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator *=(vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_mul_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator /=(vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_div_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator +=(vec<_Dim, _Storage>& A, const _Storage B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_add_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator -=(vec<_Dim, _Storage>& A, const _Storage B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_sub_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator *=(vec<_Dim, _Storage>& A, const _Storage B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_mul_mut(A, B); return A; }
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage>& operator /=(vec<_Dim, _Storage>& A, const _Storage B) noexcept { detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_div_mut(A, B); return A; }


    // Reciprocal operators
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator +(const _Storage A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_add(B, A);}
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator -(const _Storage A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_sub_recip(B, A);}
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator *(const _Storage A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_mul(B, A);}
    template<int _Dim, typename _Storage>
    static constexpr inline vec<_Dim, _Storage> operator /(const _Storage A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_div_recip(B, A);}


    // Comparative Operators
    template<int _Dim, typename _Storage>
    static constexpr inline bool operator ==(const vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { return detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_eq(A, B); }
    // TODO: Create custom vec_neq operator
    template<int _Dim, typename _Storage>
    static constexpr inline bool operator !=(const vec<_Dim, _Storage>& A, const vec<_Dim, _Storage>& B) noexcept { return !detail::vOps<typename type_selector<_Dim, _Storage>::type>::vec_eq(A, B); }

}


#endif // _ARC_VECTOR_OPERATORS_H
