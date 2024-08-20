#ifndef _VECTORS_H
#define _VECTORS_H

#include "vectors/vector.h"
#include "vectors/vector2.h"
#include "vectors/vector3.h"
#include "vectors/vector4.h"

namespace nebula::linX {

    typedef vec<2, float> vec2;
    typedef vec<2, int> vec2i;
    typedef vec<2, double> vec2d;

    typedef vec<3, float> vec3;
    typedef vec<3, int> vec3i;
    typedef vec<3, double> vec3d;

    typedef vec<4, float> vec4;
    typedef vec<4, int> vec4i;
    typedef vec<4, double> vec4d;

}

#endif //_VECTORS_H