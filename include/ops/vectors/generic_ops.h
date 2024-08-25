#ifndef _VECTOR_GENERIC_OPS_H
#define _VECTOR_GENERIC_OPS_H

#include "../../vectors/vector.h"

namespace arc::detail {

    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_add(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] + vec_b.arr[i];
            --i;
        } while (i >= 0);

        return vec_a;
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_add(
        vec<_Dim, _Type>& vec_a,
        const _Type v
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] + v;
            --i;
        } while (i >= 0);

        return vec_a;
    }



    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_sub(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] - vec_b.arr[i];
            --i;
        } while (i >= 0);

        return vec_a;
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_sub(
        vec<_Dim, _Type>& vec_a,
        const _Type v
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] - v;
            --i;
        } while (i >= 0);

        return vec_a;
    }



    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_mul(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] * vec_b.arr[i];
            --i;
        } while (i >= 0);

        return vec_a;
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_mul(
        vec<_Dim, _Type>& vec_a,
        const _Type v
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] * v;
            --i;
        } while (i >= 0);

        return vec_a;
    }


    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_div(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] / vec_b.arr[i];
            --i;
        } while (i >= 0);

        return vec_a;
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type>& generic_vec_div(
        vec<_Dim, _Type>& vec_a,
        const _Type v
    ) {
        int i = _Dim - 1;
        do {
            vec_a.arr[i] = vec_a.arr[i] / v;
            --i;
        } while (i >= 0);

        return vec_a;
    }


    template<int _Dim, typename _Type>
    static constexpr inline bool generic_vec_eq(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        int i = _Dim - 1;
        do {
            if (vec_a.arr[i] != vec_b.arr[i])
                return false;
            --i;
        } while (i >= 0);
        return true;
    }
    template<int _Dim, typename _Type>
    static constexpr inline bool generic_vec_eq(
        vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        int i = _Dim - 1;
        do {
            if (vec_a.arr[i] != b)
                return false;
            --i;
        } while (i >= 0);
        return true;
    }
}


#endif // _VECTOR_GENERIC_OPS_H
