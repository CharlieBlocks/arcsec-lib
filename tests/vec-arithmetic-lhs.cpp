#include "vectors.h"

#define ASSERT(x) { if (!(x)) return 1; }

using namespace arc;
int main(int argc, char **argv) {
    // Vector 2
    {
        vec2 a(1, 2);
        vec2 b(4, 5);

        ASSERT(a == a);
        ASSERT(!(a != a));

        a += b;
        ASSERT(a == vec2(5, 7));

        a -= b;
        ASSERT(a == vec2(1, 2));

        a *= b;
        ASSERT(a == vec2(4, 10));

        a /= b;
        ASSERT(a == vec2(1, 2));
    }


    // Vector 3
    {
        vec3 a(1, 2, 3);
        vec3 b(4, 5, 6);

        ASSERT(a == a);
        ASSERT(!(a != a));

        a += b;
        ASSERT(a == vec3(5, 7, 9));

        a -= b;
        ASSERT(a == vec3(1, 2, 3));

        a *= b;
        ASSERT(a == vec3(4, 10, 18));

        a /= b;
        ASSERT(a == vec3(1, 2, 3));
    }


    return 0;
}
