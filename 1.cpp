#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int ROWS = 100;
    const int COLS = 200;
    float **matrix = NULL;  /* указатель на двумерный массив */
    int i, j;
    int allocation_ok = 0;  /* флаг успешного выделения памяти */

    /* Инициализация генератора случайных чисел */
    srand((unsigned int)time(NULL));

    /* 1. Выделение памяти под массив указателей на строки */
    matrix = (float **)malloc(ROWS * sizeof(float *));
    if (matrix == NULL) {
        fprintf(stderr, "Ошибка: не удалось выделить память для строк\n");
        return EXIT_FAILURE;
    }

    /* 2. Выделение памяти под каждую строку */
    for (i = 0; i < ROWS; i++) {
        matrix[i] = (float *)malloc(COLS * sizeof(float));
        if (matrix[i] == NULL) {
            fprintf(stderr, "Ошибка: не удалось выделить память для строки %d\n", i);
            /* Освобождаем уже выделенную память перед выходом */
            for (j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            return EXIT_FAILURE;
        }
    }
    allocation_ok = 1;  /* память успешно выделена */

    /* 3. Заполнение массива случайными числами от -1 до 1 */
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            /* Генерация числа от -1.0 до 1.0 */
            matrix[i][j] = -1.0f + 2.0f * (float)rand() / (float)RAND_MAX;
        }
    }

    /* 4. Вывод фрагмента массива для проверки (первые 3x3 элемента) */
    printf("Фрагмент массива (первые 3 строки, 3 столбца):\n");
    for (i = 0; i < 3 && i < ROWS; i++) {
        for (j = 0; j < 3 && j < COLS; j++) {
            printf("%8.4f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("...\n");
    printf("Размер массива: %d x %d\n", ROWS, COLS);
    printf("Память выделена успешно.\n");

    /* 5. Освобождение памяти (выполняется в любом случае) */
    if (allocation_ok) {
        for (i = 0; i < ROWS; i++) {
            free(matrix[i]);
        }
        free(matrix);
        matrix = NULL;
        printf("Память освобождена.\n");
    }

    return EXIT_SUCCESS;
}