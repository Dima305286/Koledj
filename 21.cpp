#include <iostream>

using namespace std;

int F(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    return 2 * F(n - 1) - F(n - 2);
}

void test() {
    if (F(0) == 1 && F(1) == 2 && F(2) == 3 && F(3) == 4) return;
    exit(1);
}

int main() {
    test();
    int n;
    if (cin >> n) cout << F(n) << "\n";
    return 0;
}