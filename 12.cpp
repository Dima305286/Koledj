// Вариант 12. Количество четных чисел в массиве
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count_even(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    return count;
}

void test() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {1, 3, 5, 7};
    printf("Вариант 12. Тесты:\n");
    printf("[1,2,3,4,5,6]: %d четных\n", count_even(arr1, 6));
    printf("[1,3,5,7]: %d четных\n", count_even(arr2, 4));
}

int main() {
    test();
    int n;
    printf("\nВведите размер массива: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    srand(time(NULL));
    printf("Массив: ");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }
    printf("\nЧетных чисел: %d\n", count_even(arr, n));
    free(arr);
    return 0;
}