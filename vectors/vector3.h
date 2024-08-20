#ifndef _VECTOR3_H
#define _VECTOR3_H

#include "vector.h"
#include "linX/ops/vops.h"
#include "linX/intrinsics.h"

#include <type_traits>

namespace nebula::linX {

    template<typename _Type>
    struct LINX_ALIGN(16) vec<3, _Type> {
        union {
            struct { _Type x, y, z; };
            struct { _Type a, b, c; };
            struct { typename type_selector<3, _Type>::type wide; };
            struct { _Type arr[3]; };
        };

        /* Constructors */
        constexpr vec()
            : x(0), y(0), z(0) {}
        explicit constexpr vec(_Type v)
            : x(v), y(v), z(v) {}
        explicit constexpr vec(_Type x, _Type y, _Type z)
            : x(x), y(y), z(z) {}
        template<typename = typename std::enable_if<!std::is_same<void*, type_selector<3, _Type>::type>::value>::type>
        explicit constexpr vec(typename type_selector<3, _Type>::type v)
            : wide(v) {}
        
        /* Operator overloads */
        constexpr inline vec<3, _Type> operator +(const int other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_add(*this, other); }
        constexpr inline vec<3, _Type> operator +(const vec<3, _Type>& other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_add(*this, other); }

        constexpr inline vec<3, _Type> operator -(const int other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_sub(*this, other); }
        constexpr inline vec<3, _Type> operator -(const vec<3, _Type>& other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_sub(*this, other); }

        constexpr inline vec<3, _Type> operator *(const int other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_mul(*this, other); }
        constexpr inline vec<3, _Type> operator *(const vec<3, _Type>& other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_mul(*this, other); }

        constexpr inline vec<3, _Type> operator /(const int other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_div(*this, other); }
        constexpr inline vec<3, _Type> operator /(const vec<3, _Type>& other) const noexcept { return detail::vOps<typename type_selector<3, _Type>::type>::vec_div(*this, other); }
    };
}

#endif // _VECTOR3_H