// Вариант 11. Числа с разными цифрами
#include <stdio.h>
#include <stdbool.h>

bool all_digits_unique(int num) {
    if (num < 0) num = -num;
    bool digits[10] = {false};
    while (num > 0) {
        int d = num % 10;
        if (digits[d]) return false;
        digits[d] = true;
        num /= 10;
    }
    return true;
}

void find_unique_digits(int N) {
    int count = 0;
    for (int i = 0; i <= N; i++) {
        if (all_digits_unique(i)) {
            printf("%d ", i);
            if (++count % 10 == 0) printf("\n");
        }
    }
    if (count % 10 != 0) printf("\n");
    printf("Найдено: %d\n", count);
}

void test() {
    printf("Вариант 11. Тесты:\n");
    printf("123: %s\n", all_digits_unique(123) ? "разные" : "нет");
    printf("122: %s\n", all_digits_unique(122) ? "разные" : "нет");
    printf("0: %s\n", all_digits_unique(0) ? "разные" : "нет");
    printf("100: %s\n", all_digits_unique(100) ? "разные" : "нет");
}

int main() {
    test();
    int N;
    printf("\nВведите N: ");
    scanf("%d", &N);
    find_unique_digits(N);
    return 0;
}