#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    // Start measuring CPU time
    auto start = high_resolution_clock::now();

    long long k = 0;
    // Do some time-consuming process
    for (int i = 0; i < 1000000000; i++) {
        // Do some computation
        k++;
    }

    // Stop measuring CPU time
    auto stop = high_resolution_clock::now();

    // Calculate the CPU time
    auto duration = duration_cast<microseconds>(stop - start);
    double cpu_time = duration.count() / 1000000.0;

    cout << "CPU time: " << cpu_time << " seconds" << endl;

    return 0;
}
