#ifndef _ARC_VFN_VCROSS_H
#define _ARC_VFN_VCROSS_H

#include "../ops/selectors/op_selector.h"
#include "utils.h"

namespace arc {
    namespace detail {

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> generic_vcross(const vec<_Dim, _Type>& A, const vec<_Dim, _Type>& B) noexcept {
            static_assert(_Dim == 3 && type_eq<float, _Type>::value, "[arc::vcross] -> Invalid arguments, only _Dim == 3 and _Type == float are supported");;
            return vec<_Dim, _Type>(
                A.arr[1]*B.arr[2] - A.arr[2]*B.arr[1],
                A.arr[2]*B.arr[0] - A.arr[0]*B.arr[2],
                A.arr[0]*B.arr[1] - A.arr[1]*B.arr[0]
            );
        }


        template<typename _Storage>
        struct cross_selector {
            template<int _Dim, typename _Type>
            static constexpr inline vec<_Dim, _Type> cross(const vec<_Dim, _Type>& A, const vec<_Dim, _Type>& B) noexcept {
                static_assert(_Dim == 3 && type_eq<float, _Type>::value, "[arc::vcross] -> Invalid arguments, only _Dim == 3 and _Type == float are supported");;
                return vec<_Dim, _Type>(op_selector<_Storage, _Dim>::cross(A.wide, B.wide));
            }
        };

        template<>
        struct cross_selector<void*> {
            template<int _Dim, typename _Type>
            static constexpr inline vec<_Dim, _Type> cross(const vec<_Dim, _Type>& A, const vec<_Dim, _Type>& B) noexcept {
                return generic_vcross(A, B);
            }
        };
    }

    template<int _Dim, typename _Type>
    static constexpr inline vec<_Dim, _Type> vcross(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b) {
        return detail::cross_selector<typename type_selector<_Dim, _Type>::type>::cross(vec_a, vec_b);
    }
}

#endif // _ARC_VFN_VCROSS_H
