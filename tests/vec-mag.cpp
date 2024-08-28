#include "vectors.h"
#include "vfn/vmag.h"

#include "tools/tools.h"

using namespace arc;
template<int _Dim, typename _Storage>
int test_mag(_Storage vA) {
    using T = vec<_Dim, _Storage>;

    T a(vA);

    // Caluclate norm value
    _Storage norm2 = (vA*vA)*_Dim;
    _Storage norm = sqrt(norm2);

    // Test
    ASSERT(vmagnitude(a) == norm);
    ASSERT(vmagnitude2(a) == norm2);

    return 0;
}

int main(int argc, char **argv) {

    int res;

    /* Vector2 types */
    res = test_mag<2, int>(2);
    ASSERT(res == 0);

    res = test_mag<2, float>(2);
    ASSERT(res == 0);

    res = test_mag<2, double>(2);
    ASSERT(res == 0);


    /* Vector3 Types */
    res = test_mag<3, int>(2);
    ASSERT(res == 0);

    res = test_mag<3, float>(2);
    ASSERT(res == 0);

    res = test_mag<3, double>(2);
    ASSERT(res == 0);

    /* Vector4 Types */
    res = test_mag<4, int>(2);
    ASSERT(res == 0);

    res = test_mag<4, float>(2);
    ASSERT(res == 0);

    res = test_mag<4, double>(2);
    ASSERT(res == 0);


    return 0;
}
