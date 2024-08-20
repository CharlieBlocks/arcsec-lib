#ifndef _VECTOR4_H
#define _VECTOR4_H

#include "vector.h"
#include "linX/ops/vops.h"
#include "linX/intrinsics.h"

#include <type_traits>

namespace nebula::linX {

    template<typename _Type>
    struct LINX_ALIGN(32) vec<4, _Type> {
        using wide_type = typename type_selector<4, _Type>::type;

        union {
            struct { _Type x, y, z, w; };
            struct { _Type a, b, c, d; };
            struct { wide_type wide; };
            struct { _Type arr[4]; };
        };

        /* Constructors */
        constexpr vec()
            : x(0), y(0), z(0), w(0) {}
        explicit constexpr vec(_Type v)
            : x(v), y(v), z(v), w(v) {}
        explicit constexpr vec(_Type x, _Type y, _Type z, _Type w)
            : x(x), y(y), z(z), w(w) {}
        template<typename = typename std::enable_if<!std::is_same<void*, wide_type>::value>::type>
        explicit constexpr vec(wide_type v)
            : wide(v) {}

        /* Operator overloads */
        constexpr inline vec<4, _Type> operator +(const int other) const noexcept { return detail::Ops<wide_type>::vec_add(*this, other); }
        constexpr inline vec<4, _Type> operator +(const vec<4, _Type>& other) const noexcept { return detail::vOps<wide_type>::vec_add(*this, other); }

        constexpr inline vec<4, _Type> operator -(const int other) const noexcept { return detail::vOps<wide_type>::vec_sub(*this, other); }
        constexpr inline vec<4, _Type> operator -(const vec<4, _Type>& other) const noexcept { return detail::vOps<wide_type>::vec_sub(*this, other); }

        constexpr inline vec<4, _Type> operator *(const int other) const noexcept { return detail::vOps<wide_type>::vec_mul(*this, other); }
        constexpr inline vec<4, _Type> operator *(const vec<4, _Type>& other) const noexcept { return detail::vOps<wide_type>::vec_mul(*this, other); }

        constexpr inline vec<4, _Type> operator /(const int other) const noexcept { return detail::vOps<wide_type>::vec_div(*this, other); }
        constexpr inline vec<4, _Type> operator /(const vec<4, _Type>& other) const noexcept { return detail::vOps<wide_type>::vec_div(*this, other); }
    };

}

#endif // _VECTOR4_H