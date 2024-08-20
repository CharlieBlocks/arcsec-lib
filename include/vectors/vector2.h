#ifndef _VECTOR2_H
#define _VECTOR2_H

#include "vector.h"
#include "linX/ops/vops.h"
#include "linX/intrinsics.h"

#include <type_traits>

namespace nebula::linX {

    template<typename _Type>
    struct vec<2, _Type> {
        union {
            struct { _Type x, y;};
            struct { _Type a, b;};
            struct { typename type_selector<2, _Type>::type wide; };
            struct { _Type arr[2]; };
        };

        /* Constructors */
        constexpr vec()
            : x(0), y(0) {}
        explicit constexpr vec(_Type v)
            : x(v), y(v) {}
        explicit constexpr vec(_Type x, _Type y)
            : x(x), y{y} {}
        
        template<typename = typename std::enable_if<!std::is_same<void*, type_selector<2, _Type>::type>::value>::type>
        explicit constexpr vec(typename type_selector<2, _Type>::type v)
            : wide(v) {}

        /* Operator Overloads */
        constexpr inline vec<2, _Type> operator +(const int other) const noexcept {return detail::vOps<typename type_selector<2, _Type>::type>::vec_add(*this, other); }
        constexpr inline vec<2, _Type> operator +(const vec<2, _Type>& other) const noexcept { return detail::vOps<typename type_selector<2, _Type>::type>::vec_add(*this, other); }

        constexpr inline vec<2, _Type> operator -(const int other) const noexcept {return detail::vOps<typename type_selector<2, _Type>::vec_sub(*this, other); }
        constexpr inline vec<2, _Type> operator -(const vec<2, _Type>& other) const noexcept { return detail::vOps<typename type_selector<2, _Type>::type>::vec_sub(*this, other); }

        constexpr inline vec<2, _Type> operator *(const int other) const noexcept {return detail::vOps<typename type_selector<2, _Type>::type>::vec_mul(*this, other); }
        constexpr inline vec<2, _Type> operator *(const vec<2, _Type>& other) const noexcept { return detail::vOps<typename type_selector<2, _Type>::type>::vec_mul(*this, other); }

        constexpr inline vec<2, _Type> operator /(const int other) const noexcept {return detail::vOps<typename type_selector<2, _Type>::type>::vec_div(*this, other); }
        constexpr inline vec<2, _Type> operator /(const vec<2, _Type>& other) const noexcept { return detail::vOps<typename type_selector<2, _Type>::type>::vec_div(*this, other); }
    };

}

#endif // _VECTOR2_H