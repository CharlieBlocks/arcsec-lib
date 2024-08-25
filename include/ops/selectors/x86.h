#ifndef _OPSELECTOR_X86_H
#define _OPSELECTOR_X86_H
#ifdef INTRINSICS_X64

#include "intinsics.h"

namespace arc::detail {

// Integers
template<>
struct op_selector<__m128i, 3> {
    using T = __m128i;
    OP_FUNC1(int32_t, set1) { return _mm_set1_epi32(_A); }
    OP_FUNC2(T, T, add) { return _mm_add_epi32(_A, _B); }
    OP_FUNC2(T, T, sub) { return _mm_sub_epi32(_A, _B); }
    OP_FUNC2(T, T, mul) { return _mm_mul_epi32(_A, _B); }
    OP_FUNC2(T, T, div) { return _mm_div_epi32(_A, _B); }
    OP_FUNC2(T, T, eq) {
        T mask = _mm_cmpeq_epi8(_A, _B);
        return (_mm_movemask_epi32(mask) & 0xfff)  == 0xfff;
    }
};

template<>
struct op_selector<__m128i, 4> {
    using T = __m128i;
    OP_FUNC1(int32_t, set1) { return _mm_set1_epi32(_A); }
    OP_FUNC2(T, T, add) { return _mm_add_epi32(_A, _B); }
    OP_FUNC2(T, T, sub) { return _mm_sub_epi32(_A, _B); }
    OP_FUNC2(T, T, mul) { return _mm_mul_epi32(_A, _B); }
    OP_FUNC2(T, T, div) { return _mm_div_epi32(_A, _B); }
    OP_FUNC2(T, T, eq) {
        T mask = _mm_cmpeq_epi8(_A, _B);
        return _mm_movemask_epi32(mask) == 0xffff;
    }
};




// Floats
template<>
struct op_selector<__m128, 3> {
    using T = __m128;
    OP_FUNC1(float, set1) { return _mm_set1_ps(_A); }
    OP_FUNC2(T, T, add) { return _mm_add_ps(_A, _B); }
    OP_FUNC2(T, T, sub) { return _mm_sub_ps(_A, _B); }
    OP_FUNC2(T, T, mul) { return _mm_mul_ps(_A, _B); }
    OP_FUNC2(T, T, div) { return _mm_div_ps(_A, _B); }
    OP_FUNC2(T, T, eq) {
        T mask = _mm_cmpeq_ps(_A, _B);
        return (_mm_movemask_ps(mask) & 0xfff0) == 0xfff0;
    }
}
template<>
struct op_selector<__m128, 4> {
    using T = __m128d;
    OP_FUNC1(float set1) { return _mm_set1_ps(_A); }
    OP_FUNC2(T, T, add) { return _mm_add_ps(_A, _B); }
    OP_FUNC2(T, T, sub) { return _mm_sub_ps(_A, _B); }
    OP_FUNC2(T, T, mul) { return _mm_mul_ps(_A, _B); }
    OP_FUNC2(T, T, div) { return _mm_div_ps(_A, _B); }
    OP_FUNC2(T, T, eq) {
        T mask = _mm_cmpeq_ps(_A, _B);
        return _mm_movemask_ps(mask) == 0xffff;
    }
}


// Doubles
template<>
struct op_selector<__m128d, 2> {
    using T = __m128d;
    OP_FUNC1(float set1) { return _mm_set1_pd(_A); }
    OP_FUNC2(T, T, add) { return _mm_add_pd(_A, _B); }
    OP_FUNC2(T, T, sub) { return _mm_sub_pd(_A, _B); }
    OP_FUNC2(T, T, mul) { return _mm_mul_pd(_A, _B); }
    OP_FUNC2(T, T, div) { return _mm_div_pd(_A, _B); }
    OP_FUNC2(T, T, eq) {
        T mask = _mm_cmpeq_pd(_A, _B);
        return _mm_movemask_pd(mask) == 0xffff;
    }
}

}

#endif // INTRINSICS_X64
#endif // _OPSELECTOR_X86_H
