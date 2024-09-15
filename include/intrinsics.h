/*
File: Intrinsics.h

This file is used to confgirure intrinsic support across arcsec.
The file makes use of predefined defines (see root CMakeLists.txt) to chose the correct
intrinsics to use
*/

// Header guard
#ifndef _ARCSEC_INTRINSICS_H
#define _ARCSEC_INTRINSICS_H


// Using the defines we chose which implementation file to use
// as well as deffining a helper variable
#if defined(__SSE2__) || defined(__AVX2__) || defined(__AVX512__)
#include <immintrin.h> // Include all file for x64 intrinsics
#define INTRINSICS_X64
#elif defined(__NEON__)
#include <arm_neon.h> // Arm neon intrinsics (equivalent of SSE2)
#define INTRINSICS_ARM
#endif


namespace arc {

    // Define type definitions
    // void* indicates that there is no intrinsic type
#if defined(INTRINSICS_X64)

    typedef __m128i i32x4_t;
    typedef __m128 f32x4_t;
    typedef __m128 f64x2_t;

    typedef __m256i i32x8_t;
    typedef __m256 f32x8_t;
    typedef __m256 f64x4_t;

#elif defined(INTRINSICS_ARM)

    typedef int32x4_t i32x4_t;
    typedef float32x4_t f32x4_t;
    typedef float64x2_t f64x2_t;

    // Requires SVE. Not supported yet
    typedef void *i32x8_t ;
    typedef void *f32x8_t ;
    typedef void *f64x4_t ;

#else

    // Defined if there is no support
    typedef void *i32x4_t;
    typedef void *f32x4_t;
    typedef void *f64x2_t;

    typedef void *i32x8_t;
    typedef void *f32x8_t;
    typedef void *f64x4_t;

#endif




    // The type_selector structure is used to procedurally select
    // the correct intrinsic type for a given width and size
    // The selector is then specialised
    template<int _Width, typename _Size>
    struct type_selector {
        using type = void*;
    };


    // 2 width options
    template<>
    struct type_selector<2, double> { using type = f64x2_t; };

    // 3 width options
    template<>
    struct type_selector<3, int> { using type = i32x4_t; };
    // template<>
    // struct type_selector<3, float> { using type = f32x4_t; };
    template<>
    struct type_selector<3, double> { using type = f64x4_t; };

    // 4 width options
    template<>
    struct type_selector<4, int> { using type = i32x4_t; };
    template<>
    struct type_selector<4, float> { using type = f32x4_t; };
    template<>
    struct type_selector<4, double> { using type = f64x4_t; };

} // namespace arc


#endif // _ARCSEC_INTRINSICS_H
