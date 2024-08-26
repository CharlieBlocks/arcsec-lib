#include "vectors.h"
#include <iostream>

int main(int argc, char **argv) {
    arc::vec3 a(1, 2, 3);

    arc::vec3 b(1, 2, 3);

    a = a + b;
    a = a * b;
    a = a - b;
    a = a / b;

    std::cout << a.x << std::endl;

    return 0;
}
