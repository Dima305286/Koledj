#include <stdio.h>
#include <math.h>

double f1(double x) {
    return x * x - 4 * x + 3;
}

double f2(double x) {
    return sin(x);
}

double f3(double x) {
    return -x * x + 2 * x + 1;
}

double find_max(double (*f)(double), double a, double b, double step) {
    double max_val = f(a);
    for (double x = a; x <= b; x += step) {
        double val = f(x);
        if (val > max_val) max_val = val;
    }
    return max_val;
}

void test() {
    printf("Тесты:\n");
    printf("f1(x)=x^2-4x+3 на [0,4]: max = %.2f\n", find_max(f1, 0, 4, 0.001));
    printf("f2(x)=sin(x) на [0,pi]: max = %.2f\n", find_max(f2, 0, M_PI, 0.001));
    printf("f3(x)=-x^2+2x+1 на [-1,3]: max = %.2f\n", find_max(f3, -1, 3, 0.001));
}

int main() {
    test();
    double a, b;
    int choice;
    printf("\nВыберите функцию (1-3): ");
    scanf("%d", &choice);
    printf("Введите a и b: ");
    scanf("%lf %lf", &a, &b);
    
    double (*funcs[])(double) = {f1, f2, f3};
    if (choice < 1 || choice > 3) {
        printf("Неверный выбор\n");
        return 1;
    }
    
    printf("Максимум: %.6f\n", find_max(funcs[choice-1], a, b, 0.0001));
    return 0;
}