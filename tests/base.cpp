#include "vectors.h"
#include <iostream>

int main(int argc, char **argv) {
    arc::vec3 a(1, 2, 3);
    arc::vec3 b(5);

    volatile arc::vec3 c = a + b;

    // std::cout << c.x << ", " << c.y << ", " << c.z << std::endl;

    return c.x;
}
