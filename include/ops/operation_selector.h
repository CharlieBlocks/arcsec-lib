#ifndef _OPSELECTOR_H
#define _OPSELECTOR_H

#include "linX/intrinsics.h"

namespace nebula::linX::detail {

    /*
    op_selector is used to fetch the correct operation for a given
    data type    
    */
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

}

#endif // _OPSELECTOR_H