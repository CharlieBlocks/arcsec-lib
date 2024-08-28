#ifndef _ARC_VECTOR4_H
#define _ARC_VECTOR4_H

#include "vector.h"
#include "../intrinsics.h"
#include "../ops/vops.h"

#include <type_traits>
#include "../utils.h"

namespace arc {
    template<typename _Type>
    struct _ARC_ALIGN(32) vec<4, _Type> {
        using V = vec<4, _Type>;
        using wide_t = typename type_selector<4, _Type>::type;

        // Accessors/Storage
        union {
            struct { _Type x, y, z, w; };
            struct { _Type a, b, c, d; };
            struct { wide_t wide; };
            struct { _Type arr[4]; };
        };

        /* Constructors */
        constexpr vec()
            : x(0), y(0), z(0), w(0) {}
        explicit constexpr vec(_Type v)
            : x(v), y(v), z(v), w(v) {}
        explicit constexpr vec(_Type x, _Type y, _Type z, _Type w)
            : x(x), y(y), z(z), w(w) {}
        explicit constexpr vec(wide_t v)
            : wide(v) {}
    };

}

#endif // _VECTOR4_H
