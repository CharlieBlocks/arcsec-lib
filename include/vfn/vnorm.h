#ifndef _ARC_VFN_VNORM_H
#define _ARC_VFN_VNORM_H

#include "../ops/selectors/op_selector.h"
#include "../vectors.h"
#include "utils.h"

#include <cmath>


namespace arc {

    namespace detail {

        template<int _Dim, typename _Type>
        static constexpr inline vec<_Dim, _Type> generic_norm(const vec<_Dim, _Type>& A) {
            _Type mag = 0;
            int i = _Dim - 1;
            do {
                mag += A.arr[i] * A.arr[i];
                --i;
            } while (i >= 0);
            mag = sqrt(mag);

            vec<_Dim, _Type> o = A;
            i = _Dim - 1;
            do {
                o.arr[i] = A.arr[i] / mag;
                --i;
            } while (i >= 0);

            return o;
        }


        template<typename _Storage>
        struct norm_selector {
            template<int _Dim, typename _Type>
            static constexpr inline vec<_Dim, _Type> norm(const vec<_Dim, _Type>& A) noexcept {
                if (is_comptime::evaluate()) {
                    return generic_norm(A);
                }
                else {
                    _Storage A2 = op_selector<_Storage, _Dim>::mul(A.wide, A.wide);
                    _Type mag = sqrt(op_selector<_Storage, _Dim>::sum(A2));

                    return vec<_Dim, _Type>(op_selector<_Storage, _Dim>::div(A.wide, op_selector<_Storage, _Dim>::set1(mag)));
                }
            }
        };

        template<>
        struct norm_selector<void*> {
            template<int _Dim, typename _Type>
            static constexpr inline vec<_Dim, _Type> norm(const vec<_Dim, _Type>& A) noexcept {
                return generic_norm(A);
            }
        };
    }



    template<int _Dim, typename _Type>
    vec<_Dim, _Type> vnormalise(const vec<_Dim, _Type>& vec) {
        return detail::norm_selector<typename type_selector<_Dim, _Type>::type>::norm(vec);
    }


}


#endif // _ARC_VFN_VNORM_H
