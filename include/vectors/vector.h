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

}

#endif // _ARC_VECTOR_H
