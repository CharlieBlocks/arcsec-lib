#include "vectors.h"
#include "vfn/vnorm.h"

#include "tools/tools.h"

using namespace arc;
template<int _Dim, typename _Storage>
int test_norm(_Storage vA) {
    using T = vec<_Dim, _Storage>;

    T a(vA);

    // Calculate norm
    _Storage l = sqrt((vA*vA)*_Dim);
    T b(vA / l);

    ASSERT(vnormalise(a) == b);
    return 0;
}

int main(int argc, char **argv) {
    int res;

    /* Vector2 types */
    res = test_norm<2, int>(2);
    ASSERT(res == 0);

    res = test_norm<2, float>(2);
    ASSERT(res == 0);

    res = test_norm<2, double>(2);
    ASSERT(res == 0);


    /* Vector3 Types */
    res = test_norm<3, int>(2);
    ASSERT(res == 0);

    res = test_norm<3, float>(2);
    ASSERT(res == 0);

    res = test_norm<3, double>(2);
    ASSERT(res == 0);

    /* Vector4 Types */
    res = test_norm<4, int>(2);
    ASSERT(res == 0);

    res = test_norm<4, float>(2);
    ASSERT(res == 0);

    res = test_norm<4, double>(2);
    ASSERT(res == 0);


    return 0;
}
