#ifndef _ARC_MATRIX_H
#define _ARC_MATRIX_H

#include "../intrinsics.h"
#include "../utils.h"

namespace arc {

    template<int _Rows, int _Cols, typename _Storage>
    struct _ARC_ALIGN(16) mat {
        static const int HCap = _Cols;

        // Base storage type
        _Storage arr[_Rows * _Cols];
    };

}

#endif // _ARC_MATRIX_H
