#ifndef _ARC_MAT3_H
#define _ARC_MAT3_H

#include "matrix.h"
#include "../utils.h"

namespace arc {

    template<typename _Type>
    struct _ARC_ALIGN(16) mat<3, 3, _Type> {
        using M = mat<3, 3, _Type>;
        using wide_t = typename type_selector<3, _Type>::type;

        static const int HCap = 4;

        union {
            // Note that, depsite being a 3x3 matrix we define 4x4 elemnts
            // This is to enable intrinsics
            // Might want to predicate this on whether intrinsics are enabled
            // As this will increase the memory bandwith required
            struct { _Type arr[16]; };
            struct { wide_t wide[3]; };
            struct {
                _Type a; _Type b; _Type c; _Type _1;
                _Type d; _Type e; _Type f; _Type _2;
                _Type g; _Type h; _Type i; _Type _3;
            };
        };

        // Constructors
        constexpr mat()
        :
        a(0),
        b(0),
        c(0),
        d(0),
        e(0),
        f(0),
        g(0),
        h(0),
        i(0)
        {}
        constexpr mat(_Type x)
            :
        a(x),
        b(x),
        c(x),
        d(x),
        e(x),
        f(x),
        g(x),
        h(x),
        i(x) {}

        explicit constexpr mat(wide_t x, wide_t y, wide_t z)
            : wide({x, y ,z}) {}
    };

}

#endif // _ARC_MAT3_H
