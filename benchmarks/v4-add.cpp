#include "vectors.h"
#include "vfn/vcross.h"
#include "benchmarking.h"
#include <iostream>

// Fifty-million
#define ITERATIONS 10000000

void Benchmark_v4add_arc() {
    BenchmarkState state("v4add_arc", ITERATIONS);

    arc::vec4 result(0);
    arc::vec4 a(1);


    state.Start();
    do {
        result += a;
    } while (!state.Step());
    state.Stop();

    std::cout << result.x << std::endl;
    std::cout << "v4add_arc: " << state.GetNanoseconds() << "ns" << std::endl;
    std::cout << "Total: " << state.GetTotalSeconds() << "s" << std::endl;
}
void Benchmark_v4add_c() {
    BenchmarkState state("v4add_c", ITERATIONS);

    volatile float result[4] = { 0 };
    volatile float a[4] = { 1, 1, 1, 1 };

    state.Start();
    do {
        result[0] += a[0];// + b[0];
        result[1] += a[1];// + b[1];
        result[2] += a[2];// + b[2];
        result[3] += a[3];// + b[3];
    } while (!state.Step());
    state.Stop();

    std::cout << result[0] << std::endl;
    std::cout << "v4add_c: " << state.GetNanoseconds() << "ns" << std::endl;
    std::cout << "Total: " << state.GetTotalSeconds() << "s" << std::endl;
}

void Benchmark_v3cross_arc() {
    BenchmarkState state("v3cross_arc", ITERATIONS);

    arc::vec3 result(0);
    arc::vec3 a(1, 2, 3);
    arc::vec3 b(3, 2, 1);

    state.Start();
    do {
       result += arc::vcross(a, b);
    } while(!state.Step());
    state.Stop();

    std::cout << result.x << std::endl;
    std::cout << "v3cross_arc: " << state.GetNanoseconds() << "ns" << std::endl;
    std::cout << "Total: " << state.GetTotalSeconds() << "s" << std::endl;
}
void Benchmark_v3cross_c() {
    BenchmarkState state("v3cross_c", ITERATIONS);

    volatile float result[3] = {0};
    volatile float a[3] = {1, 2, 3};
    volatile float b[3] = {3, 2, 1};

    state.Start();
    do {
        result[0] += a[1]*b[2] - a[2]*b[1];
        result[1] += a[2]*b[0] - a[0]*b[2];
        result[2] += a[0]*b[1] - a[1]*b[0];
    } while (!state.Step());
    state.Stop();

    std::cout << result[0] << std::endl;
    std::cout << "vcross3_c: " << state.GetNanoseconds() << "ns" << std::endl;
    std::cout << "Total: " << state.GetTotalSeconds() << "s" << std::endl;
}


int main(void) {

    Benchmark_v4add_c();
    Benchmark_v4add_arc();

    return 0;
}
