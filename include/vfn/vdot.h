#ifndef _ARC_VFN_VDOT_H
#define _ARC_VFN_VDOT_H

#include "../ops/selectors/op_selector.h"
#include "utils.h"

namespace arc {
    namespace detail {

        template<int _Dim, typename _Type>
        static constexpr inline _Type generic_vdot(const vec<_Dim, _Type>& A, const vec<_Dim, _Type>& B) noexcept {
            vec<_Dim, _Type> AB = A * B;

            _Type sum = 0;
            int i = _Dim - 1;
            do {
                sum += AB.arr[i];
            } while (--i >= 0);

            return sum;
        }


        template<typename _Storage>
        struct dot_selector {
            template<int _Dim, typename _Type>
            static constexpr inline _Type dot(const vec<_Dim, _Type>& A, const vec<_Dim, _Type>& B) {
                if (is_comptime::evaluate()) {
                    return generic_vdot(A, B);
                }
                else {
                    _Storage AB = op_selector<_Storage, _Dim>::mul(A.wide, B.wide);
                    _Type sum = op_selector<_Storage, _Dim>::sum(AB);

                    return sum;
                }
            }
        };

        template<>
        struct dot_selector<void*> {
            template<int _Dim, typename _Type>
            static constexpr inline _Type dot(const vec<_Dim, _Type>& A, const vec<_Dim, _Type>& B) {
                return generic_vdot(A, B);
            }
        };
    }

    template<int _Dim, typename _Type>
    static constexpr inline _Type vdot(const vec<_Dim, _Type>& vec_a, const vec<_Dim, _Type>& vec_b) {
        return detail::dot_selector<typename type_selector<_Dim, _Type>::type>::dot(vec_a, vec_b);
    }
}


#endif // _ARC_VFN_VDOT_H
