#ifndef _ARC_VECTOR3_H
#define _ARC_VECTOR3_H

#include "vector.h"
#include "../intrinsics.h"
#include "../ops/vops.h"

#include <type_traits>
#include "../utils.h"

namespace arc {
    template<typename _Type>
    struct _ARC_ALIGN(16) vec<3, _Type> {
        using V = vec<3, _Type>;
        using wide_t = typename type_selector<3, _Type>::type;

        // Accessors/Storage
        union {
            struct { _Type x, y, z; };
            struct { _Type a, b, c; };
            struct { _Type u, v, w; };
            struct { wide_t wide; };
            struct { _Type arr[4]; };
        };


        // Constructors
        constexpr vec()
            : x(0), y(0), z(0) { }
        explicit constexpr vec(_Type v)
            : x(v), y(v), z(v) { }
        explicit constexpr vec(_Type x, _Type y, _Type z)
            : x(x), y(y), z(z) { }

        explicit constexpr vec(wide_t v)
            : wide(v) {}
    };
}

#endif // _ARC_VECTOR3_H
