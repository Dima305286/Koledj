#include <stdio.h>
#include <stdlib.h>

void multiply_matrices(int **A, int **B, int **C, int m, int n, int p) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int **allocate_matrix(int rows, int cols) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    return matrix;
}

void free_matrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) free(matrix[i]);
    free(matrix);
}

void print_matrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void test() {
    printf("Тест умножения матриц:\n");
    
    int **A = allocate_matrix(2, 3);
    int **B = allocate_matrix(3, 2);
    int **C = allocate_matrix(2, 2);
    
    int dataA[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int dataB[3][2] = {{7, 8}, {9, 10}, {11, 12}};
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++) A[i][j] = dataA[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++) B[i][j] = dataB[i][j];
    
    multiply_matrices(A, B, C, 2, 3, 2);
    
    printf("A:\n"); print_matrix(A, 2, 3);
    printf("B:\n"); print_matrix(B, 3, 2);
    printf("A * B:\n"); print_matrix(C, 2, 2);
    
    free_matrix(A, 2);
    free_matrix(B, 3);
    free_matrix(C, 2);
}

int main() {
    test();
    
    int m, n, p;
    printf("\nВведите размеры матриц m,n,p (A[mxn], B[nxp]): ");
    scanf("%d %d %d", &m, &n, &p);
    
    int **A = allocate_matrix(m, n);
    int **B = allocate_matrix(n, p);
    int **C = allocate_matrix(m, p);
    
    printf("Введите матрицу A:\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) scanf("%d", &A[i][j]);
    
    printf("Введите матрицу B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++) scanf("%d", &B[i][j]);
    
    multiply_matrices(A, B, C, m, n, p);
    
    printf("Результат:\n");
    print_matrix(C, m, p);
    
    free_matrix(A, m);
    free_matrix(B, n);
    free_matrix(C, m);
    
    return 0;
}