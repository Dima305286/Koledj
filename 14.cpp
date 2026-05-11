// Вариант 14. Удаление ведущих и конечных пробелов
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim(char *str) {
    int start = 0, end = strlen(str) - 1;
    while (isspace(str[start])) start++;
    while (end >= start && isspace(str[end])) end--;
    int len = end - start + 1;
    for (int i = 0; i < len; i++) str[i] = str[start + i];
    str[len] = '\0';
}

void test() {
    char s1[] = "  hello  ";
    char s2[] = "world";
    char s3[] = "   ";
    printf("Вариант 14. Тесты:\n");
    trim(s1); printf("'%s'\n", s1);
    trim(s2); printf("'%s'\n", s2);
    trim(s3); printf("'%s'\n", s3);
}

int main() {
    test();
    char str[256];
    printf("\nВведите строку: ");
    getchar();
    fgets(str, 256, stdin);
    str[strcspn(str, "\n")] = 0;
    trim(str);
    printf("Результат: '%s'\n", str);
    return 0;
}