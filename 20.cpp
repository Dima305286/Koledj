#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return x * x - 4.0;
}

double find_zero(double a, double b, double eps) {
    double mid = (a + b) / 2.0;
    if (b - a < eps) return mid;
    if (f(a) * f(mid) <= 0) return find_zero(a, mid, eps);
    return find_zero(mid, b, eps);
}

void test() {
    double res = find_zero(0.0, 5.0, 0.0001);
    if (abs(res - 2.0) < 0.001) exit(0);
    else exit(1);
}

int main() {
    double a, b, eps;
    if (cin >> a >> b >> eps) {
        cout << find_zero(a, b, eps) << "\n";
    } else {
        test();
    }
    return 0;
}