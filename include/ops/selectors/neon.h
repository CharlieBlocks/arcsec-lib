#ifndef _OPSELECTOR_NEON_H
#define _OPSELECTOR_NEON_H

// Only enable for neoon platforms
#ifdef INTRINSICS_ARM

#include "intrinsics.h"

namespace arc::detail {

// Integers
template<>
struct op_selector<int32x4_t, 3> {
    using T = int32x4_t;
    OP_FUNC1(int32_t, set1) { return vdupq_n_s32(_A); }
    OP_FUNC2(T, T, add) { return vaddq_s32(_A, _B); }
    OP_FUNC2(T, T, sub) { return vsubq_s32(_A, _B); }
    OP_FUNC2(T, T, mul) { return vmulq_s32(_A, _B); }
    OP_FUNC2(T, T, div) {
        // Neon does not implement an integer divide instruction
        // Hence we create a new output vector and place into it
        // the results of _A / _B
        T O;
        O[0] = _A[0] / _B[0];
        O[1] = _A[1] / _B[1];
        O[2] = _A[2] / _B[2];
        return O;
    }
    OP_FUNC2_RET(T, T, eq, bool) {
        // Neon does not implement a movemask instruction like AVX does
        // Hence we compare _A and _B, then we reinterpret it into
        // 8 16bit integers.
        // vsrn then takes only the upper 4 values and shrinks the type
        // to 8bit integers
        // This can then be reinterpreted into a u64 and converted out
        // of vector form
        // Since this is op_selector is for 3 elements we apply a
        // 48 bit mask and then check that all bits are set
        uint16x8_t eqMask = vreinterpretq_u16_u32(vceqq_s32(_A, _B));
        uint8x8_t res = vshrn_n_u16(eqMask, 4);
        uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
        matches &= 0xffffffffffffull;
        return matches == 0xffffffffffffull;
    }
    OP_FUNC1_RET(T, sum, int32_t) {
        // Requires the extra set to prevent invalid result
        // Doing a set on a register should be qucker than subtracting from result
        _A[3] = 0;
        return vaddvq_s32(_A);
    }
};


template<>
struct op_selector<int32x4_t, 4> {
    using T = int32x4_t;
    OP_FUNC1(int32_t, set1) { return vdupq_n_s32(_A); }
    OP_FUNC2(T, T, add) { return vaddq_s32(_A, _B); }
    OP_FUNC2(T, T, sub) { return vsubq_s32(_A, _B); }
    OP_FUNC2(T, T, mul) { return vmulq_s32(_A, _B); }
    OP_FUNC2(T, T, div) {
        // See op_selector<int32x4_t, 3> for reasoning
        T O;
        O[0] = _A[0] / _B[0];
        O[1] = _A[1] / _B[1];
        O[2] = _A[2] / _B[2];
        O[3] = _A[3] / _B[4];
        return O;
    }
    OP_FUNC2_RET(T, T, eq, bool) {
        // See op_selector<int32x4_t, 3> for explanation
        uint16x8_t eqMask = vreinterpretq_u16_u32(vceqq_s32(_A, _B));
        uint8x8_t res = vshrn_n_u16(eqMask, 4);
        uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
        return matches == 0xffffffffffffffffull;
    }
    OP_FUNC1_RET(T, sum, int32_t) {
        return vaddvq_s32(_A);
    }
};




// Floats
template<>
struct op_selector<float32x4_t, 3> {
    using T = float32x4_t;
    OP_FUNC1(float, set1) { return vdupq_n_f32(_A); }
    OP_FUNC2(T, T, add) { return vaddq_f32(_A, _B); }
    OP_FUNC2(T, T, sub) { return vsubq_f32(_A, _B); }
    OP_FUNC2(T, T, mul) { return vmulq_f32(_A, _B); }
    // This will result in garbage data for the fourth component
    // It is assumed that this component is ignored by other instructions
    OP_FUNC2(T, T, div) { return vdivq_f32(_A, _B); }
    OP_FUNC2_RET(T, T, eq, bool) {
        uint16x8_t mask = vreinterpretq_u16_u32(vceqq_f32(_A, _B));
        uint8x8_t res = vshrn_n_u16(mask, 4);
        uint64x1_t temp = vreinterpret_u64_u8(res);
        uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
        return (matches & 0xffffffffffffull) == 0xffffffffffffull;
    }
    OP_FUNC1_RET(T, sum, float) {
        _A[3] = 0;
        return vaddvq_f32(_A);
    }
    OP_FUNC2(T, T, cross) {
        float32x4_t result = {0};
        asm volatile(
            "ext %0.16B, %1.16B, %1.16B, #0xc   \n\t"
            "ext v1.16B, %2.16B, %2.16B, #0xc   \n\t"
            "mov.s %1[3], %1[0]                 \n\t"
            "mov.s %2[3], %2[0]                 \n\t"
            "fmul %0.4S, %0.4S, %2.4S           \n\t"
            "fmls %0.4S, v1.4S, %1.4S           \n\t"
            "ext %0.16B, %0.16B, %0.16B, #0x8   \n\t"
            "mov.s %0[2], %0[3]                  \n\t"
            : "=&w"(result)
            : "w"(_A), "w"(_B)
            : "v1"
        );
        return result;
    }
};

template<>
struct op_selector<float32x4_t, 4> {
    using T = float32x4_t;
    OP_FUNC1(float, set1) { return vdupq_n_f32(_A); }
    OP_FUNC2(T, T, add) { return vaddq_f32(_A, _B); }
    OP_FUNC2(T, T, sub) { return vsubq_f32(_A, _B); }
    OP_FUNC2(T, T, mul) { return vmulq_f32(_A, _B); }
    OP_FUNC2(T, T, div) { return vdivq_f32(_A, _B);}
    OP_FUNC2_RET(T, T, eq, bool) {
        uint16x8_t mask = vreinterpretq_u16_u32(vceqq_f32(_A, _B));
        uint8x8_t res = vshrn_n_u16(mask, 4);
        uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
        return matches == 0xffffffffffffffffull;
    }
    OP_FUNC1_RET(T, sum, float) {
        return vaddvq_f32(_A);
    }
};




// Doubles
template<>
struct op_selector<float64x2_t, 2> {
    using T = float64x2_t;
    OP_FUNC1(double, set1) { return vdupq_n_f64(_A); }
    OP_FUNC2(T, T, add) { return vaddq_f64(_A, _B); }
    OP_FUNC2(T, T, sub) { return vsubq_f64(_A, _B); }
    OP_FUNC2(T, T, mul) { return vmulq_f64(_A, _B); }
    OP_FUNC2(T, T, div) { return vdivq_f64(_A, _B); }
    OP_FUNC2_RET(T, T, eq, bool) {
        uint16x8_t mask = vreinterpretq_u16_u64(vceqq_f64(_A, _B));
        uint8x8_t res = vshrn_n_u16(mask, 4);
        uint64_t matches = vget_lane_u64(vreinterpret_u64_u8(res), 0);
        return matches == 0xffffffffffffffffull;
    }
    OP_FUNC1_RET(T, sum, double) {
        return vaddvq_f64(_A);
    }
};

}

#endif // INTRINSICS_NEON
#endif // _OPSELECTOR_NEON_H
