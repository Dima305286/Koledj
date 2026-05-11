#include <stdio.h>

int sum_of_digits(int num) {
    return num / 100 + (num / 10) % 10 + num % 10;
}

void find_numbers(int N) {
    if (N < 0 || N > 27) {
        printf("Для трехзначных чисел сумма цифр от 0 до 27\n");
        return;
    }
    int count = 0;
    for (int i = 100; i <= 999; i++) {
        if (sum_of_digits(i) == N) {
            printf("%d ", i);
            if (++count % 10 == 0) printf("\n");
        }
    }
    if (count % 10 != 0) printf("\n");
    printf("Найдено: %d чисел\n", count);
}

void test() {
    printf("Тесты:\n");
    printf("Сумма цифр 123: %d\n", sum_of_digits(123));
    printf("Сумма цифр 999: %d\n", sum_of_digits(999));
    printf("Сумма цифр 100: %d\n", sum_of_digits(100));
    printf("Сумма цифр 555: %d\n", sum_of_digits(555));
    printf("\nЧисла с суммой цифр 1:\n");
    find_numbers(1);
}

int main() {
    test();
    int N;
    printf("\nВведите сумму цифр N (0-27): ");
    scanf("%d", &N);
    if (N < 0 || N > 27) {
        printf("Сумма должна быть от 0 до 27\n");
        return 1;
    }
    printf("Трехзначные числа с суммой цифр %d:\n", N);
    find_numbers(N);
    return 0;
}