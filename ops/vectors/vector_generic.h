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

#include "linX/intrinsics.h"
#include "linX/vectors/vector.h"
#include "vector_vectorised.h"
#include "generic_ops.h"

namespace nebula::linX::detail {

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
        static constexpr inline vec<_Dim, _Type> vec_add(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_add(const vec<_Dim, _Type>& vec_a, const _Type v); 

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_sub(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_sub(const vec<_Dim, _Type>& vec_a, const _Type v);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_mul(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_mul(const vec<_Dim, _Type>& vec_a, const _Type v);

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_div(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b);
        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> vec_div(const vec<_Dim, _Type>& vec_a, const _Type v);

        
        
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
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_add(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_add(vec_a, vec_b);
    }

    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_add(
        const vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_add(vec_a, v);
    }

    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_sub(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_sub(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_sub(
        const vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_sub(vec_a, v);
    }

    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_mul(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_mul(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_mul(
        const vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_mul(vec_a, v);
    }

    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_div(
        const vec<_Dim, _Type>& vec_a,
        const vec<_Dim, _Type>& vec_b
    ) {
        return generic_vec_div(vec_a, vec_b);
    }
    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vOps<void*>::vec_div(
        const vec<_Dim, _Type> & vec_a,
        const _Type v
    ) {
        return generic_vec_div(vec_a, v);
    }
}


#endif // _VECTOR_GENERIC_H