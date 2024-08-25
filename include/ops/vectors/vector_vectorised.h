#ifndef _VECTOR_SPECIALISED_H
#define _VECTOR_SPECIALISED_H

#include "../../intrinsics.h"
#include "../../vectors/vector.h"
#include "../operation_selector.h"
#include "generic_ops.h"

#include "utils.h"

namespace arc::detail {

    /*
    vOps contains generic operations
    These operations are specilised to alignments using the _Size template
    */
    template<typename _Storage>
    struct vOps {
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_add(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_add(vec<_Dim, _Type>& vec_a, const _Type b);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_sub(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_sub(vec<_Dim, _Type>& vec_a, const _Type b);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_mul(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_mul(vec<_Dim, _Type>& vec_a, const _Type b);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_div(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_div(vec<_Dim, _Type>& vec_a, const _Type b);


        // Comparison operators
        template<int _Dim, typename _Type>
        static constexpr inline bool vec_eq(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline bool vec_eq(vec<_Dim, _Type>& vec_a, const _Type vec_b);
    };

    // Implementations
    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_add(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        if (is_comptime::evaluate()) {
            vec_a = generic_vec_add(vec_a, vec_b);
            return vec_a;
        } else {
            vec_a.wide = op_selector<_Storage>::add(vec_a.wide, vec_b.wide);
            return vec_a;
        }
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_add(
        vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        if (is_comptime::evaluate()) {
            auto o = generic_vec_add(vec_a, b);
            return o;
        } else {
            auto scalar = op_selector<_Storage>::set1(b);
            vec_a.wide = op_selector<_Storage>::add(vec_a.wide, scalar);
            return vec_a;
        }
    }

    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_sub(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        if (is_comptime::evaluate()) {
            vec_a = generic_vec_sub(vec_a, vec_b);
            return vec_a;
        } else {
            vec_a.wide = op_selector<_Storage>::sub(vec_a.wide, vec_b.wide);
            return vec_a;
        }
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_sub(
        vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        if (is_comptime::evaluate()) {
            auto o = generic_sub_add(vec_a, b);
            return o;
        } else {
            auto scalar = op_selector<_Storage>::set1(b);
            vec_a.wide = op_selector<_Storage>::sub(vec_a.wide, scalar);
            return vec_a;
        }
    }

    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_mul(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        if (is_comptime::evaluate()) {
            vec_a = generic_vec_mul(vec_a, vec_b);
            return vec_a;
        } else {
            vec_a.wide = op_selector<_Storage>::mul(vec_a.wide, vec_b.wide);
            return vec_a;
        }
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_mul(
        vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        if (is_comptime::evaluate()) {
            auto o = generic_vec_mul(vec_a, b);
            return o;
        } else {
            auto scalar = op_selector<_Storage>::set1(b);
            vec_a.wide = op_selector<_Storage>::mul(vec_a.wide, scalar);
            return vec_a;
        }
    }

    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_div(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        if (is_comptime::evaluate()) {
            vec_a = generic_vec_div(vec_a, vec_b);
            return vec_a;
        } else {
            vec_a.wide = op_selector<_Storage>::div(vec_a.wide, vec_b.wide);
            return vec_a;
        }
    }
    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<_Storage>::vec_div(
        vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        if (is_comptime::evaluate()) {
            auto o = generic_vec_div(vec_a, b);
            return o;
        } else {
            auto scalar = op_selector<_Storage>::set1(b);
            vec_a.wide = op_selector<_Storage>::div(vec_a.wide, scalar);
            return vec_a;
        }
    }


    // Comparison operators
    template<typename _Storage>
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline bool vOps<_Storage>::vec_eq(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        if (is_comptime::evaluate()) {
            bool o = generic_vec_eq(vec_a, vec_b);
            return 0;
        } else {
            return op_selector<_Storage>::eq(vec_a.wide, vec_b.wide);
        }
    }
}

#endif // _VECTOR_SPECIALISED_H
