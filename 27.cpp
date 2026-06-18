#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    ofstream out("data.bin", ios::binary);
    for (int i = 0; i < 10000; ++i) {
        int val = (rand() % 2 == 0) ? 1 : -1;
        out.write(reinterpret_cast<char*>(&val), sizeof(int));
    }
    out.close();

    int* arr = new int[10000];
    ifstream in("data.bin", ios::binary);
    in.read(reinterpret_cast<char*>(arr), 10000 * sizeof(int));
    in.close();

    long long sum = 0;
    for (int i = 0; i < 10000; ++i) {
        sum += arr[i];
    }
    delete[] arr;

    cout << sum << "\n";
    return 0;
}