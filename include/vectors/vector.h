#ifndef _ARC_VECTOR_H
#define _ARC_VECTOR_H

namespace arc {

    // Define generic vector implementation
    template<int _Dim, typename _Type>
    struct vec {
        // Base storage. This has no accessor overrides
        _Type arr[_Dim];

        // TODO: Add operator overloads
    };



    // Helper defines
    #define ARITHMETIC_OPERATORS \
    constexpr inline V operator +(const _Type other) noexcept { return detail::vOps<wide_t>::vec_add(*this, other); } \
    constexpr inline V operator -(const _Type other) noexcept { return detail::vOps<wide_t>::vec_sub(*this, other); } \
    constexpr inline V operator *(const _Type other) noexcept { return detail::vOps<wide_t>::vec_mul(*this, other); } \
    constexpr inline V operator /(const _Type other) noexcept { return detail::vOps<wide_t>::vec_div(*this, other); } \
    constexpr inline V operator +(const V& other) noexcept { return detail::vOps<wide_t>::vec_add(*this, other); } \
    constexpr inline V operator -(const V& other) noexcept { return detail::vOps<wide_t>::vec_sub(*this, other); } \
    constexpr inline V operator *(const V& other) noexcept { return detail::vOps<wide_t>::vec_mul(*this, other); } \
    constexpr inline V operator /(const V& other) noexcept { return detail::vOps<wide_t>::vec_div(*this, other); } \


    #define INPLACE_OPERATORS \
    constexpr inline V& operator +=(const _Type other) noexcept { detail::vOps<wide_t>::vec_add_mut(*this, other); return *this; } \
    constexpr inline V& operator -=(const _Type other) noexcept { detail::vOps<wide_t>::vec_sub_mut(*this, other); return *this; } \
    constexpr inline V& operator *=(const _Type other) noexcept { detail::vOps<wide_t>::vec_mul_mut(*this, other); return *this; } \
    constexpr inline V& operator /=(const _Type other) noexcept { detail::vOps<wide_t>::vec_div_mut(*this, other); return *this; } \
    constexpr inline V& operator +=(const V& other) noexcept { detail::vOps<wide_t>::vec_add_mut(*this, other); return *this; } \
    constexpr inline V& operator -=(const V& other) noexcept { detail::vOps<wide_t>::vec_sub_mut(*this, other); return *this; } \
    constexpr inline V& operator *=(const V& other) noexcept { detail::vOps<wide_t>::vec_mul_mut(*this, other); return *this; } \
    constexpr inline V& operator /=(const V& other) noexcept { detail::vOps<wide_t>::vec_div_mut(*this, other); return *this; }

    #define COMPARISON_OPERATORS \
    constexpr inline bool operator ==(const V& other) noexcept { return detail::vOps<wide_t>::vec_eq(*this, other); } \
    constexpr inline bool operator ==(const _Type other) noexcept { return detail::vOps<wide_t>::vec_eq(*this, other); } \
    constexpr inline bool operator !=(const V& other) noexcept { return !(*this == other); } \
    constexpr inline bool operator !=(const _Type& other) noexcept { return !(*this == other); }


}

#endif // _ARC_VECTOR_H
