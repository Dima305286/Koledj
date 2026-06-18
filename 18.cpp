#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

double f1(double x) { return x * x; }
double f2(double x) { return x * x * x; }
double f3(double x) { return sin(x); }
double f4(double x) { return exp(x); }

double derivative(double (*f)(double), double x, double h = 1e-8)
{
    return (f(x + h) - f(x - h)) / (2.0 * h);
}

void test()
{
    assert(fabs(derivative(f1, 3.0) - 6.0) < 1e-5);
    assert(fabs(derivative(f2, 2.0) - 12.0) < 1e-5);
    assert(fabs(derivative(f3, 0.0) - 1.0) < 1e-5);
    assert(fabs(derivative(f4, 0.0) - 1.0) < 1e-5);
    assert(fabs(derivative(f4, 1.0) - exp(1.0)) < 1e-5);
}

int main()
{
    test();
    double x = 2.0;
    cout << derivative(f1, x) << endl;
    cout << derivative(f2, x) << endl;
    cout << derivative(f3, x) << endl;
    cout << derivative(f4, x) << endl;
    return 0;
}