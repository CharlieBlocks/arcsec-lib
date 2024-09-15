#ifndef _ARC_MAT2_H
#define _ARC_MAT2_H

#include "matrix.h"
#include "../utils.h"

namespace arc {

    template<typename _Type>
    struct _ARC_ALIGN(16) mat<2, 2, _Type> {
        using M = mat<2, 2, _Type>;
        // Given taht this is a 2x2 matrix we can squeeze everything into a
        // 4 wide vector
        using wide_t = typename type_selector<2, _Type>::type;

        union {
            struct { _Type arr[4]; };
            struct { wide_t wide1; wide_t wide2; };
        };


        // Constructors
        constexpr mat(_Type a, _Type b, _Type c, _Type d)
        {
            arr[0] = a;
            arr[1] = b;
            arr[2] = c;
            arr[3] = d;
        }
    };

}


#endif // _ARC_MAT2_H
