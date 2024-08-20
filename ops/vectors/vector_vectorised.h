#ifndef _VECTOR_SPECIALISED_H
#define _VECTOR_SPECIALISED_H

#include "linX/intrinsics.h"
#include "linX/vectors/vector.h"
#include "../operation_selector.h"
#include "generic_ops.h"

#include "utils/comptime.h"

#define CHECK_COMPTIME(x, y) \
if (is_comptime::evaluate()) { \
    y \
} else { \
    x \
} \

namespace nebula::linX::detail {

    /*
    vOps contains generic operations
    These operations are specilised to alignments using the _Size template
    */
    template<typename _Storage>
    struct vOps {
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_add(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_add(const vec<_Dim, _Type>& vec_a, const _Type b);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_sub(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_sub(const vec<_Dim, _Type>& vec_a, const _Type b);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_mul(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_mul(const vec<_Dim, _Type>& vec_a, const _Type b);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_div(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_div(const vec<_Dim, _Type>& vec_a, const _Type b);
    };

    // Implementations
    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_add(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        if (is_comptime::evaluate()) {
            auto o = generic_vec_add(vec_a, vec_b);
            return o;
        } else {
            auto o = op_selector<_Storage>::add(vec_a.wide, vec_b.wide);
            return vec<_Dim, _Type>(o);
        }
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_add(
        const vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        auto o = CHECK_COMPTIME({ auto scalar = op_selector<_Storage>::set(b); op_selector<_Storage>::add(vec_a.wide, scalar); }, generic_vec_add(vec_a, b) )
        return vec<_Dim, _Type>(o);
    }

    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_sub(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        auto o = CHECK_COMPTIME(op_selector<_Storage>::sub(vec_a.wide, vec_b.wide), generic_vec_sub(vec_a, vec_b) )
        return vec<_Dim, _Type>(o);
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_sub(
        const vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        auto o = CHECK_COMPTIME({ auto scalar = op_selector<_Storage>::set(b); op_selector<_Storage>::sub(vec_a.wide, scalar); }, generic_vec_sub(vec_a, b) )
        return vec<_Dim, _Type>(o);
    }

    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_mul(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        auto o = CHECK_COMPTIME(op_selector<_Storage>::mul(vec_a.wide, vec_b.wide), generic_vec_mul(vec_a, vec_b) )
        return vec<_Dim, _Type>(o);
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_mul(
        const vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        auto o = CHECK_COMPTIME({ auto scalar = op_selector<_Storage>::set(b); op_selector<_Storage>::mul(vec_a.wide, scalar); }, generic_vec_mul(vec_a, b) )
        return vec<_Dim, _Type>(o);
    }

    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_div(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        auto o = CHECK_COMPTIME(op_selector<_Storage>::div(vec_a.wide, vec_b.wide), generic_vec_div(vec_a, vec_b) )
        return vec<_Dim, _Type>(o);
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<_Storage>::vec_div(
        const vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        auto o = CHECK_COMPTIME({ auto scalar = op_selector<_Storage>::set(b); op_selector<_Storage>::div(vec_a.wide, scalar); }, generic_vec_div(vec_a, b) )
        return vec<_Dim, _Type>(o);
    }
}

#endif // _VECTOR_SPECIALISED_H 