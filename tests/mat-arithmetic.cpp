#include "matrices.h"
#include "tools/tools.h"

#include <iostream>

using namespace arc;
void print_mat(mat33 m) {
    std::cout << m.arr[0] << ", " << m.arr[1] << ", " << m.arr[2] << ",\n";
    std::cout << m.arr[3] << ", " << m.arr[4] << ", " << m.arr[5] << ",\n";
    std::cout << m.arr[6] << ", " << m.arr[7] << ", " << m.arr[8] << std::endl;
}

template<int _Rows, int _Cols, typename _Storage>
int test_mat(_Storage  vA, _Storage vB) {
    using M = mat<_Rows, _Cols, _Storage>;

    M a(vA);
    M b(vB);


    // Test equality operators
    ASSERT(vA == vA);
    ASSERT(!(vA != vA));


    // Test basic arithmetic operators
    ASSERT((a + b) == M(vA + vB));
    ASSERT((a - b) == M(vA - vB));
    ASSERT((a * b) == M(vA * vB));
    ASSERT((a / b) == M(vA / vB));

    // Copy assignment
    M c = a;
    ASSERT(c == a);

    // Test inplace operators
    c += b;
    ASSERT(c == M(vA + vB));

    c = a;
    c -= b;
    ASSERT(c == M(vA - vB));

    c = a;
    c *= b;
    ASSERT(c == M(vA * vB));

    c = a;
    c /= b;
    ASSERT(c == M(vA / vB));


    // Test reciprocal operators
    ASSERT(vB + a == M(vB + vA));
    ASSERT(vB - a == M(vB - vA));
    ASSERT(vB * a == M(vB * vA));
    ASSERT(vB / a == M(vB / vA));

    return 0;
}

int main(int arc, char **argv) {
    int res;

    res = test_mat<3, 3, float>(2, 3);
    ASSERT(res == 0);

    return 0;
}
