#include "vectors.h"
#include "vfn/vcross.h"

#include "tools/tools.h"

#include <iostream>

using namespace arc;
int main(int argc, char **argv) {
    vec3 a(0, 1, 2);
    vec3 b(2, 1, 0);

    auto res = vcross(a, b);
    std::cout << res.x << ", " << res.y << ", " << res.z << std::endl;

    ASSERT(vcross(a, b) == vec3(-2, 4, -2));

    return 0;
}
