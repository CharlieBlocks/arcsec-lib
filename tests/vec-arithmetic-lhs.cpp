#include "vectors.h"

#define ASSERT(x) { if (!(x)) return 1; }

using namespace arc;



template<int _Dim, typename _Storage>
int test_vec(_Storage vA, _Storage vB) {
    using T = vec<_Dim, _Storage>;

    // Create vectors
    T a(vA);
    T b(vB);

    // Test equality operators
    ASSERT(vA == vA);
    ASSERT(!(vA != vA));

    // Test basic arithmetic operators
    ASSERT((a + b) == T(vA + vB));
    ASSERT((a - b) == T(vA - vB));
    ASSERT((a * b) == T(vA * vB));
    ASSERT((a / b) == T(vA / vB));

    // Copy assignment
    T c = a;
    ASSERT(c == a);

    // Test inplace operators
    c += b;
    ASSERT(c == T(vA + vB));

    c = a;
    c -= b;
    ASSERT(c == T(vA - vB));

    c = a;
    c *= b;
    ASSERT(c == T(vA * vB));

    c = a;
    c /= b;
    ASSERT(c == T(vA / vB));


    return 0;
}


int main(int argc, char **argv) {

    int res;

    /* Vector2 Types */
    res = test_vec<2, int>(2, 3); // Integer
    ASSERT(res == 0);

    res = test_vec<2, float>(2, 3); // Float
    ASSERT(res == 0);

    res = test_vec<2, double>(2, 3); // Double
    ASSERT(res == 0);


    /* Vector3 Types */
    res = test_vec<3, int>(2, 3); // Integer
    ASSERT(res == 0);

    res = test_vec<3, float>(2, 3); // Float
    ASSERT(res == 0);

    res = test_vec<3, double>(2, 3); // Double
    ASSERT(res == 0);


    /* Vector4 Types */
    res = test_vec<4, int>(2, 3); // Integer
    ASSERT(res == 0);

    res = test_vec<4, float>(2, 3); // Float
    ASSERT(res == 0);

    res = test_vec<4, double>(2, 3); // Double
    ASSERT(res == 0);

    return 0;
}
