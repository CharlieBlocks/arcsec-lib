#ifndef _VECTOR_GENERIC_OPS_H
#define _VECTOR_GENERIC_OPS_H

#include "linX/vectors/vector.h"

namespace nebula::linX::detail {

template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_add(
    const vec<_Dim, _Type>& vec_a,
    const vec<_Dim, _Type>& vec_b
) {
    vec<_Dim, _Type> o;


    int i = _Dim - 1;
    do {
        //o.arr[i] = vec_a.arr[i] + vec_b.arr[i];
        --i;
    } while (i >= 0);

    return o;
}
template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_add(
    const vec<_Dim, _Type>& vec_a,
    const _Type v
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] + v;
        --i;
    } while (i >= 0);

    return o;
}



template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_sub( 
    const vec<_Dim, _Type>& vec_a,
    const vec<_Dim, _Type>& vec_b
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] - vec_b.arr[i];
        --i;
    } while (i >= 0);

    return o;
}
template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_sub(
    const vec<_Dim, _Type>& vec_a,
    const _Type v
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] - v;
        --i;
    } while (i >= 0);

    return o;
}



template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_mul( 
    const vec<_Dim, _Type>& vec_a,
    const vec<_Dim, _Type>& vec_b
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] * vec_b.arr[i];
        --i;
    } while (i >= 0);

    return o;
}
template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_mul(
    const vec<_Dim, _Type>& vec_a,
    const _Type v
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] * v;
        --i;
    } while (i >= 0);

    return o;
}


template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_div( 
    const vec<_Dim, _Type>& vec_a,
    const vec<_Dim, _Type>& vec_b
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] / vec_b.arr[i];
        --i;
    } while (i >= 0);

    return o;
}
template<int _Dim, typename _Type>
static constexpr inline vec<_Dim, _Type> generic_vec_div(
    const vec<_Dim, _Type>& vec_a,
    const _Type v
) {
    vec<_Dim, _Type> o;

    int i = _Dim - 1;
    do {
        o.arr[i] = vec_a.arr[i] / v;
        --i;
    } while (i >= 0);

    return o;
}

}


#endif // _VECTOR_GENERIC_OPS_H