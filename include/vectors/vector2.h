/*
This is override for the arc::vec class for width 2.
*/

#ifndef _ARC_VECTOR2_H
#define _ARC_VECTOR2_H


#include "vector.h"
#include "../intrinsics.h"
#include "../ops/vops.h"

#include <type_traits>

namespace arc {

    template<typename _Type>
    struct vec<2, _Type> {
        using V = vec<2, _Type>;
        using wide_t = typename type_selector<2, _Type>::type;

        // Anonymous union provides various accessor overrides
        union {
            struct { _Type x, y; };
            struct { _Type a, b; };
            struct { _Type u, v; };
            struct { wide_t wide; };
            struct { _Type arr[2]; };
        };


        // Constructors
        constexpr vec()
            : x(0), y(0) {}
        explicit constexpr vec(_Type v)
            : x(v), y(v) {}
        explicit constexpr vec(_Type x, _Type y)
            : x(x), y(y) {}

        explicit constexpr vec(typename type_selector<2, _Type>::type v)
            : wide(v) {}
    };
}

#endif // _ARC_VECTOR2_H
