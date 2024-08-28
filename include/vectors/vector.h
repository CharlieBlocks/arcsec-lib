#ifndef _ARC_VECTOR_H
#define _ARC_VECTOR_H

#include "../intrinsics.h"

namespace arc {

    // Define generic vector implementation
    template<int _Dim, typename _Type>
    struct vec {
        // Base storage. This has no accessor overrides
        _Type arr[_Dim];
    };
}

#endif // _ARC_VECTOR_H
