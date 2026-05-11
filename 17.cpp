// Вариант 17. Последнее вхождение символа в строку
#include <stdio.h>
#include <string.h>

int last_occurrence(const char *str, char ch) {
    for (int i = strlen(str) - 1; i >= 0; i--) {
        if (str[i] == ch) return i;
    }
    return -1;
}

void test() {
    printf("Вариант 17. Тесты:\n");
    printf("'hello' 'l': %d\n", last_occurrence("hello", 'l'));
    printf("'hello' 'o': %d\n", last_occurrence("hello", 'o'));
    printf("'hello' 'x': %d\n", last_occurrence("hello", 'x'));
}

int main() {
    test();
    char str[256], ch;
    printf("\nВведите строку: ");
    getchar();
    fgets(str, 256, stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Введите символ: ");
    scanf("%c", &ch);
    int pos = last_occurrence(str, ch);
    if (pos != -1) printf("Позиция: %d\n", pos);
    else printf("Символ не найден\n");
    return 0;
}