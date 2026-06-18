#include <iostream>
#include <vector>

using namespace std;

void factorize_recursive(int n, int divisor, vector<int>& result) {
    if (n <= 1) return;
    if (divisor * divisor > n) {
        result.push_back(n);
        return;
    }
    if (n % divisor == 0) {
        result.push_back(divisor);
        factorize_recursive(n / divisor, divisor, result);
    } else {
        factorize_recursive(n, divisor + 1, result);
    }
}

vector<int> get_prime_factors(int n) {
    vector<int> result;
    factorize_recursive(n, 2, result);
    return result;
}

void test() {
    if (get_prime_factors(12) != vector<int>{2, 2, 3}) exit(1);
    if (get_prime_factors(13) != vector<int>{13}) exit(1);
    if (get_prime_factors(100) != vector<int>{2, 2, 5, 5}) exit(1);
    if (get_prime_factors(1) != vector<int>{}) exit(1);
}

int main() {
    test();
    int n;
    if (cin >> n && n > 1) {
        vector<int> factors = get_prime_factors(n);
        for (int factor : factors) {
            cout << factor << " ";
        }
        cout << "\n";
    }
    return 0;