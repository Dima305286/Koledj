#include <iostream>
#include <chrono>

using namespace std;

void measure_enter_interval() {
    cin.get();
    auto start = chrono::steady_clock::now();
    cin.get();
    auto end = chrono::steady_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n";
}

int main() {
    measure_enter_interval();
    return 0;
}