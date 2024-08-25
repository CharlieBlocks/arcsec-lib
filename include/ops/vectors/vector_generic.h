/*
Implemented Functions:
- Add
- AddS
- Sub
- SubS
- Mul
- MulS
- Div
- Divs
*/

#ifndef _VECTOR_GENERIC_H
#define _VECTOR_GENERIC_H

#include "../../intrinsics.h"
#include "../../vectors/vector.h"
#include "vector_vectorised.h"
#include "generic_ops.h"
#include "utils.h"

namespace arc::detail {

    template<>
    struct vOps<void*> {

        /*
        Generic Arithmetic:
        - Add
        - Sub
        - Mul
        - Div
        - Exp
        - Log
        */
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_add(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_add(vec<_Dim, _Type>& vec_a, const _Type v);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_sub(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_sub(vec<_Dim, _Type>& vec_a, const _Type v);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_mul(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_mul(vec<_Dim, _Type>& vec_a, const _Type v);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_div(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type>& vec_div(vec<_Dim, _Type>& vec_a, const _Type v);


        /*
        Comparison Operators
        */
        template<int _Dim, typename _Type>
        static constexpr inline bool vec_eq(vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline bool vec_eq(vec<_Dim, _Type>& vec_a, const _Type b);



        /*
        Vector Operations
        - Sum
        - Product
        - Dot Product
        - Cross Product
        */

        /* Trig */
    };


    // Implementations
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_add(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_add(vec_a, vec_b);
    }

    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_add(
        vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_add(vec_a, v);
    }

    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_sub(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_sub(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_sub(
        vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_sub(vec_a, v);
    }

    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_mul(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_mul(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_mul(
        vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_mul(vec_a, v);
    }

    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_div(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_div(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline vec<_Dim, _Type>& vOps<void*>::vec_div(
        vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_div(vec_a, v);
    }


    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline bool vOps<void*>::vec_eq(
        vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_eq(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    OOL_STATIC constexpr inline bool vOps<void*>::vec_eq(
        vec<_Dim, _Type>& vec_a,
        const _Type b
    ) {
        return generic_vec_eq(vec_a, b);
    }
}


#endif // _VECTOR_GENERIC_H
