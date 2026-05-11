// Вариант 13. Нахождение нулевого элемента в матрице
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool check_zeros(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bool row_has_zero = false;
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                row_has_zero = true;
                break;
            }
        }
        if (!row_has_zero) return false;
    }
    for (int j = 0; j < cols; j++) {
        bool col_has_zero = false;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] == 0) {
                col_has_zero = true;
                break;
            }
        }
        if (!col_has_zero) return false;
    }
    return true;
}

int main() {
    int data1[3][3] = {{1,0,3}, {0,5,6}, {7,8,0}};
    int data2[2][3] = {{1,0,3}, {4,5,0}};
    
    int *m1[3] = {data1[0], data1[1], data1[2]};
    int *m2[2] = {data2[0], data2[1]};
    
    printf("Вариант 13. Тесты:\n");
    printf("Матрица 1: %s\n", check_zeros(m1, 3, 3) ? "да" : "нет");
    printf("Матрица 2: %s\n", check_zeros(m2, 2, 3) ? "да" : "нет");

    int rows, cols;
    printf("\nВведите размеры матрицы: ");
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    int *ptrs[rows];
    for (int i = 0; i < rows; i++) {
        ptrs[i] = matrix[i];
        for (int j = 0; j < cols; j++) scanf("%d", &matrix[i][j]);
    }
    
    printf("В каждой строке и столбце есть 0: %s\n", 
           check_zeros(ptrs, rows, cols) ? "да" : "нет");
    return 0;
}