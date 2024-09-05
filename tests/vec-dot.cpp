#include "vectors.h"
#include "vfn/vdot.h"

#include "tools/tools.h"

using namespace arc;
template<int _Dim, typename _Storage>
int test_dot(_Storage vA) {
    using T = vec<_Dim, _Storage>;

    T a(vA);
    T b(vA);

    // Calculate dot product
    _Storage dot = (vA*vA)*_Dim;

    // Test
    ASSERT(vdot(a, b) == dot);

    return 0;
}

int main(int argc, char **argv) {

    int res;

    /* Vector2 types */
    res = test_dot<2, int>(2);
    ASSERT(res == 0);

    res = test_dot<2, float>(2);
    ASSERT(res == 0);

    res = test_dot<2, double>(2);
    ASSERT(res == 0);

    /* Vector3 types */
    res = test_dot<3, int>(2);
    ASSERT(res == 0);

    res = test_dot<3, float>(2);
    ASSERT(res == 0);

    res = test_dot<3, double>(2);
    ASSERT(res == 0);

    /* Vector4 types */
    res = test_dot<4, int>(2);
    ASSERT(res == 0);

    res = test_dot<4, float>(2);
    ASSERT(res == 0);

    res = test_dot<4, double>(2);
    ASSERT(res == 0);


    return 0;
}
