// Вариант 15. Сортировка одномерного массива
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main() {
    double test_arr[] = {3.5, 1.2, 4.8, 2.1, 5.0};
    printf("Вариант 15. Тест:\n");
    sort(test_arr, 5);
    for (int i = 0; i < 5; i++) printf("%.1f ", test_arr[i]);
    printf("\n");
    
    int n;
    printf("\nВведите размер массива: ");
    scanf("%d", &n);
    double arr[n];
    srand(time(0));
    printf("До сортировки: ");
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) / 10.0;
        printf("%.1f ", arr[i]);
    }
    sort(arr, n);
    printf("\nПосле сортировки: ");
    for (int i = 0; i < n; i++) printf("%.1f ", arr[i]);
    printf("\n");
    return 0;
}