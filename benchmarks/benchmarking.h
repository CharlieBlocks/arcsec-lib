/*
benchmarking.h contains various benchmarking utilities
*/

#include <chrono>

class BenchmarkState {
public:
    BenchmarkState(const char* name, int its)
    : targetIterations(its), benchmarkName(name), iterations(0) {}
    ~BenchmarkState() {}

    void Start() {
        start = std::chrono::high_resolution_clock::now();
    }
    bool Step() {
        ++iterations;
        return iterations >= targetIterations;
    }
    void Stop() {
        end = std::chrono::high_resolution_clock::now();
    }

    long long GetNanoseconds() {
        long long duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

        return duration / targetIterations;
    }
    long long GetMicroseconds() { return this->GetNanoseconds() / 1000; }
    long long GetMilliseconds() { return this->GetNanoseconds() / 1000000; }
    long long GetTotalSeconds() { return std::chrono::duration_cast<std::chrono::microseconds>(end - start).count(); }

private:
    const char *benchmarkName;

    unsigned int iterations;
    unsigned int targetIterations;

    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
};
