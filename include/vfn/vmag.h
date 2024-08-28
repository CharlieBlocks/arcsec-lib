#ifndef _ARC_VFN_VMAG_H
#define _ARC_VFN_VMAG_H

#include "../ops/selectors/op_selector.h"
#include "utils.h"

// Replace with custom functions
#include <cmath>

namespace arc {

    namespace detail {

        template<int _Dim, typename _Type>
        static constexpr inline _Type generic_mag(const vec<_Dim, _Type>& A) noexcept {
            _Type mag = 0;
            int i = _Dim - 1;
            do {
                mag += A.arr[i] * A.arr[i];
                --i;
            } while (i >= 0);

            return sqrt(mag);
        }
        template<int _Dim, typename _Type>
        static constexpr inline _Type generic_mag2(const vec<_Dim, _Type>& A) noexcept {
            _Type mag = 0;
            int i = _Dim - 1;
            do {
                mag += A.arr[i] * A.arr[i];
                --i;
            } while (i >= 0);

            return mag;
        }

        template<typename _Storage>
        struct mag_selector {
            template<int _Dim, typename _Type>
            static constexpr inline _Type mag(const vec<_Dim, _Type>& A) noexcept {
                if (is_comptime::evaluate()) {
                    return generic_mag(A);
                }
                else {
                    _Storage A2 = op_selector<_Storage, _Dim>::mul(A.wide, A.wide);
                    _Type sum = op_selector<_Storage, _Dim>::sum(A2);

                    return sqrt(sum);
                }
            }
            template<int _Dim, typename _Type>
            static constexpr inline _Type mag2(const vec<_Dim, _Type>& A) noexcept {
                if (is_comptime::evaluate()) {
                    return generic_mag2(A);
                }
                else {
                    _Storage A2 = op_selector<_Storage, _Dim>::mul(A.wide, A.wide);
                    _Type sum = op_selector<_Storage, _Dim>::sum(A2);

                    return sum;
                }
            }
        };


        template<>
        struct mag_selector<void*> {
            template<int _Dim, typename _Type>
            static constexpr inline _Type mag(const vec<_Dim, _Type>& A) noexcept {
                // Implement generic selector
                return generic_mag(A);
            }
            template<int _Dim, typename _Type>
            static constexpr inline _Type mag2(const vec<_Dim, _Type>& A) noexcept {
                return generic_mag2(A);
            }
        };
    }



    template<int _Dim, typename _Type>
    static constexpr inline _Type vmagnitude(const vec<_Dim, _Type>& vec) {
        return detail::mag_selector<typename type_selector<_Dim, _Type>::type>::mag(vec);
    }
    template<int _Dim, typename _Type>
    static constexpr inline _Type vmagnitude2(const vec<_Dim, _Type>& vec) {
        return detail::mag_selector<typename type_selector<_Dim, _Type>::type>::mag2(vec);
    }

}


#endif // _ARC_VFN_VMAG_H
