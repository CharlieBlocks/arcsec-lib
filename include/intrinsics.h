#ifndef _INTRINSICS_H
#define _INTRINSICS_H

#include <immintrin.h>


namespace nebula::linX {

    template<int _Width, typename _Size>
    struct type_selector {
        using type = void*;
    };


#if defined(__SSE__) || defined(__SSE2__) || defined(__SSE3__)
#define INTRINSICS_128
#endif

#if defined(__AVX__) || defined(__AVX2__)
#define INTRINSICS_256
#endif


#ifdef INTRINSICS_128

    template<>
    struct type_selector<2, double> { using type = __m128d; };

    template<>
    struct type_selector<3, int> { using type = __m128i; };
    // template<>
    // struct type_selector<3, float> { using type = __m128; };

    template<>
    struct type_selector<4, int> { using type = __m128i; };
    template<>
    struct type_selector<4, float> { using type = __m128; };


#endif // INTRINSICS_128

#ifdef INTRINSICS_256

    template<>
    struct type_selector<3, double> { using type = __m256d; };
    template<>
    struct type_selector<4, double> { using type = __m256d; };
    template<>
    struct type_selector<8, int> { using type = __m256i; };
    template<>
    struct type_selector<8, float> { using type = __m256; };

#endif // INTRINSICS_256


#define LINX_FUNC __fastcall
#define LINX_IFUNC __vectorcall

#if defined(_MSC_VER)
#define LINX_ALIGN(a) __declspec(align(a))
#else
#define LINX_ALIGNED(x) x
#endif

}


#endif // _INTRINSICS_H