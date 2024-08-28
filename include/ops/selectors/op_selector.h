#ifndef _OPSELECTOR_H
#define _OPSELECTOR_H

#include "intrinsics.h"

#define OP_FUNC1(arg1, name) static inline T name(arg1 _A) noexcept
#define OP_FUNC2(arg1, arg2, name) static inline T name(arg1 _A, arg2 _B) noexcept
#define OP_FUNC1_RET(arg1, name, ret) static inline ret name(arg1 _A) noexcept
#define OP_FUNC2_RET(arg1, arg2, name, ret) static inline ret name(arg1 _A, arg2 _B) noexcept

namespace arc::detail {

    template<typename _Storage, int _Dim>
    struct op_selector {};

}

#include "x86.h"
#include "neon.h"

#endif // _OPSELECTOR_H
