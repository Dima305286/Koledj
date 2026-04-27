#include <iostream>
#include <vector>
#include <iomanip>

std::vector<int> find_lucky_tickets() {
    std::vector<int> lucky;
    
    for (int t = 0; t < 1000000; ++t) {
        int left = t / 1000;
        int right = t % 1000;
        
        int left_sum = left / 100 + (left / 10) % 10 + left % 10;
        int right_sum = right / 100 + (right / 10) % 10 + right % 10;
        
        if (left_sum == right_sum) {
            lucky.push_back(t);
        }
    }
    return lucky;
}

void test() {
    auto tickets = find_lucky_tickets();
    
    std::cout << "=== Тесты ===\n";
    std::cout << "Количество счастливых билетов: " << tickets.size() 
              << " (ожидается 55252) - " 
              << (tickets.size() == 55252 ? "OK" : "FAIL") << '\n';
    std::cout << "Первый билет: " << tickets.front() 
              << " (ожидается 1001) - " 
              << (tickets.front() == 1001 ? "OK" : "FAIL") << '\n';
    std::cout << "Последний билет: " << tickets.back() 
              << " (ожидается 999999) - " 
              << (tickets.back() == 999999 ? "OK" : "FAIL") << '\n';
}

int main() {
    test();
    
    auto tickets = find_lucky_tickets();
    
    std::cout << "\nВсего счастливых билетов: " << tickets.size() << '\n';
    std::cout << "Процент: " << std::fixed << std::setprecision(2) 
              << (100.0 * tickets.size() / 1000000) << "%\n\n";
    
    std::cout << "Первые 10 счастливых билетов:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << std::setw(6) << std::setfill('0') << tickets[i] << '\n';
    }
    
    return 0;
}