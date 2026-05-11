// Вариант 16. Сортировка строк
#include <stdio.h>
#include <string.h>

void sort_strings(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char tmp[100];
                strcpy(tmp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], tmp);
            }
        }
    }
}

int main() {
    char test_arr[4][100] = {"banana", "apple", "cherry", "date"};
    printf("Вариант 16. Тест:\n");
    sort_strings(test_arr, 4);
    for (int i = 0; i < 4; i++) printf("%s ", test_arr[i]);
    printf("\n");

    int n;
    printf("\nВведите количество строк: ");
    scanf("%d", &n);
    char arr[n][100];
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);
    sort_strings(arr, n);
    printf("Результат: ");
    for (int i = 0; i < n; i++) printf("%s ", arr[i]);
    printf("\n");
    return 0;
}