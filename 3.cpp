#include <iostream>
#include <iomanip>

template<typename T>
void compute_machine_constants() {
    // Машинный эпсилон
    T epsilon = static_cast<T>(1.0);
    while (static_cast<T>(1.0) + epsilon / static_cast<T>(2.0) > static_cast<T>(1.0)) {
        epsilon /= static_cast<T>(2.0);
    }
    
    // Машинный ноль
    T zero = static_cast<T>(1.0);
    while (zero / static_cast<T>(2.0) > static_cast<T>(0.0)) {
        zero /= static_cast<T>(2.0);
    }
    
    std::cout << "Машинный эпсилон: " << std::scientific << epsilon << '\n';
    std::cout << "Машинный ноль:    " << zero << '\n';
    
    // Проверка
    std::cout << "1.0 + eps/2 == 1.0: " 
              << ((static_cast<T>(1.0) + epsilon/static_cast<T>(2.0)) == static_cast<T>(1.0)) << '\n';
    std::cout << "1.0 + eps > 1.0:   " 
              << ((static_cast<T>(1.0) + epsilon) > static_cast<T>(1.0)) << '\n';
}

int main() {
    std::cout << "=== float ===\n";
    compute_machine_constants<float>();
    
    std::cout << "\n=== double ===\n";
    compute_machine_constants<double>();
    
    std::cout << "\n=== long double ===\n";
    compute_machine_constants<long double>();
    
    return 0;
}