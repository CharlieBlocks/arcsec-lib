#ifndef _VECTOR_OPS_H
#define _VECTOR_OPS_H


namespace arc::detail {

    #define VTYPE vec<_Dim, _Type>

    /*
    vOps contains generic operations
    These operations are specilised to alignments using the _Size template
    */
    template<typename _Storage>
    struct vOps {

        // Addition
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_add(const VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_add(const vec<_Dim, _Type>& vec_a, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_add_mut(VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline void vec_add_mut(VTYPE& vec_a, const _Type scalar);
        // No reciprocal required. Addition is communitative


        // Subtraction
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_sub(const VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_sub(const VTYPE& vec_a, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_sub_mut(VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline void vec_sub_mut(VTYPE& vec_a, const _Type vec_b);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_sub_recip(const VTYPE& vec_a, const _Type scalar);



        // Multiplication
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_mul(const VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_mul(const vec<_Dim, _Type>& vec_a, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_mul_mut(VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline void vec_mul_mut(VTYPE& vec_a, const _Type scalar);
        // No reciprocal required. Addition is communitative


        // Division
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_div(const VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_div(const VTYPE& vec_a, const _Type scalar);
        template<int _Dim, typename _Type> static constexpr inline void vec_div_mut(VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline void vec_div_mut(VTYPE& vec_a, const _Type vec_b);
        template<int _Dim, typename _Type> static constexpr inline VTYPE vec_div_recip(const VTYPE& vec_a, const _Type scalar);


        // Equality operator
        template<int _Dim, typename _Type> static constexpr inline bool vec_eq(const VTYPE& vec_a, const VTYPE& vec_b);
        template<int _Dim, typename _Type> static constexpr inline bool vec_eq(const VTYPE& vec_a, const _Type scalar);
        // No reciprocal required
    };

    #undef VTYPE
}


/* Include Specialisations */
#define _VOPS_FILE // Guard to prevent implementation files being included without vops.h

// Vectorised specialisations
#include "vectors/vector_vectorised.h"

// Generic implementations
#include "vectors/vector_generic.h"

#undef _VOPS_FILE

#endif // _VECTOR_OPS_H
