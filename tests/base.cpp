#include "vectors.h"
#include <iostream>

int main(int argc, char **argv) {
    arc::vec3 a(1, 2, 3);

    float f;
    std::cin >> f;
    arc::vec3 b(f);

    a = a + b;
    a = a * b;
    a = a - b;
    a = a / b;

    std::cout << a.x << std::endl;

    // std::cout << c.x << ", " << c.y << ", " << c.z << std::endl;

    return a.x;
}
