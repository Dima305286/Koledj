#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int num) {
    if (num < 0) return false;
    int original = num, reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

void find_palindromes(int N) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (is_palindrome(i)) {
            printf("%d ", i);
            if (++count % 10 == 0) printf("\n");
        }
    }
    if (count % 10 != 0) printf("\n");
    printf("Всего: %d\n", count);
}

void test() {
    printf("Тесты:\n");
    printf("121: %s\n", is_palindrome(121) ? "да" : "нет");
    printf("123: %s\n", is_palindrome(123) ? "да" : "нет");
    printf("0: %s\n", is_palindrome(0) ? "да" : "нет");
    printf("-121: %s\n", is_palindrome(-121) ? "да" : "нет");
    printf("1001: %s\n", is_palindrome(1001) ? "да" : "нет");
}

int main() {
    test();
    int N;
    printf("Введите N: ");
    scanf("%d", &N);
    if (N < 0) {
        printf("N должно быть >= 0\n");
        return 1;
    }
    find_palindromes(N);
    return 0;
}