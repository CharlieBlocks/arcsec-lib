#ifndef _OPSELECTOR_H
#define _OPSELECTOR_H

#include "intrinsics.h"

namespace arc::detail {

    /*
    op_selector is used to fetch the correct operation for a given
    data type
    */

    #if defined(INTRINSICS_X64)
    template<typename _Storage>
    struct op_selector {};
    template<>
    struct op_selector<__m128i> {
        static inline __m128i set1(int _I) noexcept { return _mm_set1_epi32(_I); };
        static inline __m128i add(__m128i _A, __m128i _B) noexcept { return _mm_add_epi32(_A, _B); }
        static inline __m128i sub(__m128i _A, __m128i _B) noexcept { return _mm_sub_epi32(_A, _B); }
        static inline __m128i mul(__m128i _A, __m128i _B) noexcept { return _mm_mullo_epi32(_A, _B); }
        static inline __m128i div(__m128i _A, __m128i _B) noexcept { return _mm_div_epi32(_A, _B); }
    };
    template<>
    struct op_selector<__m128> {
        static inline __m128 set1(float _I) noexcept { return _mm_set1_ps(_I); };
        static inline __m128 add(__m128 _A, __m128 _B) noexcept { return _mm_add_ps(_A, _B); }
        static inline __m128 sub(__m128 _A, __m128 _B) noexcept { return _mm_sub_ps(_A, _B); }
        static inline __m128 mul(__m128 _A, __m128 _B) noexcept { return _mm_mul_ps(_A, _B); }
        static inline __m128 div(__m128 _A, __m128 _B) noexcept { return _mm_div_ps(_A, _B); }
    };
    template<>
    struct op_selector<__m128d> {
        static inline __m128d set1(double _I) noexcept { return _mm_set1_pd(_I); };
        static inline __m128d add(__m128d _A, __m128d _B) noexcept { return _mm_add_pd(_A, _B); }
        static inline __m128d sub(__m128d _A, __m128d _B) noexcept { return _mm_sub_pd(_A, _B); }
        static inline __m128d mul(__m128d _A, __m128d _B) noexcept { return _mm_mul_pd(_A, _B); }
        static inline __m128d div(__m128d _A, __m128d _B) noexcept { return _mm_div_pd(_A, _B); }
    };
    template<>
    struct op_selector<__m256i> {
        static inline __m256i set1(int _I) noexcept { return _mm256_set1_epi32(_I); }
        static inline __m256i add(__m256i _A, __m256i _B) noexcept { return _mm256_add_epi32(_A, _B); }
        static inline __m256i sub(__m256i _A, __m256i _B) noexcept { return _mm256_sub_epi32(_A, _B); }
        static inline __m256i mul(__m256i _A, __m256i _B) noexcept { return _mm256_mul_epi32(_A, _B); }
        static inline __m256i div(__m256i _A, __m256i _B) noexcept { return _mm256_div_epi32(_A, _B); }
    };
    template<>
    struct op_selector<__m256> {
        static inline __m256 set1(float _I) noexcept { return _mm256_set1_ps(_I); }
        static inline __m256 add(__m256 _A, __m256 _B) noexcept { return _mm256_add_ps(_A, _B); }
        static inline __m256 sub(__m256 _A, __m256 _B) noexcept { return _mm256_sub_ps(_A, _B); }
        static inline __m256 mul(__m256 _A, __m256 _B) noexcept { return _mm256_mul_ps(_A, _B); }
        static inline __m256 div(__m256 _A, __m256 _B) noexcept { return _mm256_div_ps(_A, _B); }
    };
    template<>
    struct op_selector<__m256d> {
        static inline __m256d set1(double _I) noexcept { return _mm256_set1_pd(_I); }
        static inline __m256d add(__m256d _A, __m256d _B) noexcept { return _mm256_add_pd(_A, _B); }
        static inline __m256d sub(__m256d _A, __m256d _B) noexcept { return _mm256_sub_pd(_A, _B); }
        static inline __m256d mul(__m256d _A, __m256d _B) noexcept { return _mm256_mul_pd(_A, _B); }
        static inline __m256d div(__m256d _A, __m256d _B) noexcept { return _mm256_div_pd(_A, _B); }
    };

    #elif defined(INTRINSICS_ARM)

    template<typename _Storage>
    struct op_selector {};
    template<>
    struct op_selector<i32x4_t> {
        static inline i32x4_t set1(int _I) noexcept { return vdupq_n_s32(_I); }
        static inline i32x4_t add(i32x4_t _A, i32x4_t _B) noexcept { return vaddq_s32(_A, _B); }
        static inline i32x4_t sub(i32x4_t _A, i32x4_t _B) noexcept { return vsubq_s32(_A, _B); }
        static inline i32x4_t mul(i32x4_t _A, i32x4_t _B) noexcept { return vmulq_s32(_A, _B); }
        static inline i32x4_t div(i32x4_t _A, i32x4_t _B) noexcept {
            // NEON does not implement an integer divide
            // Because why would that be useful?
            _A[0] /= _B[0];
            _A[1] /= _B[1];
            _A[2] /= _B[2];
            _A[3] /= _B[3];
            return _A;
        }
        static inline bool eq(i32x4_t _A, i32x4_t _B) noexcept {
            uint16x8_t equalMask = vreinterpretq_u16_u32(vceqq_s32(_A, _B));
            uint8x8_t res = vshrn_n_u16(equalMask, 4);
            uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
            matches &= 0xffffffffffffull;
            return matches == 0xffffffffffffull;
        }
    };
    template<>
    struct op_selector<f32x4_t> {
        static inline f32x4_t set1(int _I) noexcept { return vdupq_n_f32(_I); }
        static inline f32x4_t add(f32x4_t _A, f32x4_t _B) noexcept { return vaddq_f32(_A, _B); }
        static inline f32x4_t sub(f32x4_t _A, f32x4_t _B) noexcept { return vsubq_f32(_A, _B); }
        static inline f32x4_t mul(f32x4_t _A, f32x4_t _B) noexcept { return vmulq_f32(_A, _B); }
        static inline f32x4_t div(f32x4_t _A, f32x4_t _B) noexcept { return vdivq_f32(_A, _B); }
        static inline bool eq(f32x4_t _A, f32x4_t _B) noexcept {
            for (int i = 0; i < 4; ++i) {
                if (_A[i] != _B[i])
                    return false;
            }
            return true;
        }
    };
    template<>
    struct op_selector<f64x2_t> {
        static inline f64x2_t set1(int _I) noexcept { return vdupq_n_f64(_I); }
        static inline f64x2_t add(f64x2_t _A, f64x2_t _B) noexcept { return vaddq_f64(_A, _B); }
        static inline f64x2_t sub(f64x2_t _A, f64x2_t _B) noexcept { return vsubq_f64(_A, _B); }
        static inline f64x2_t mul(f64x2_t _A, f64x2_t _B) noexcept { return vmulq_f64(_A, _B); }
        static inline f64x2_t div(f64x2_t _A, f64x2_t _B) noexcept { return vdivq_f64(_A, _B); }
        static inline bool eq(f64x2_t _A, f64x2_t _B) noexcept {
            for (int i = 0; i < 2; ++i) {
                if (_A[i] != _B[i])
                    return false;
            }
            return true;
        }
    };

    #endif // INTRINSICS_X64
}

#endif // _OPSELECTOR_H
