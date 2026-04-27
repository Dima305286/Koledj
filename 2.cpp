#include <iostream>
#include <iomanip>
#include <random>

int main() {
    constexpr int ROWS = 100;
    constexpr int COLS = 200;
    int** matrix = nullptr;
    bool allocation_ok = true;

    matrix = new (std::nothrow) int*[ROWS];
    if (!matrix) {
        std::cerr << "Ошибка: не удалось выделить память для строк\n";
        return EXIT_FAILURE;
    }

    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = nullptr;
    }

    for (int i = 0; i < ROWS; ++i) {
        matrix[i] = new (std::nothrow) int[COLS];
        if (!matrix[i]) {
            std::cerr << "Ошибка: не удалось выделить память для строки " << i << '\n';
            allocation_ok = false;
            break;
        }
    }

    if (!allocation_ok) {
        for (int i = 0; i < ROWS; ++i) {
            if (matrix[i]) {
                delete[] matrix[i];
                matrix[i] = nullptr;
            }
        }
        delete[] matrix;
        matrix = nullptr;
        return EXIT_FAILURE;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-3, 10);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            matrix[i][j] = dist(gen);
        }
    }

    std::cout << "Фрагмент массива (первые 5 строк, 5 столбцов):\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << std::setw(5) << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "...\n";
    std::cout << "Размер массива: " << ROWS << " x " << COLS << '\n';
    std::cout << "Память выделена успешно.\n";

    int min_val = matrix[0][0];
    int max_val = matrix[0][0];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (matrix[i][j] < min_val) min_val = matrix[i][j];
            if (matrix[i][j] > max_val) max_val = matrix[i][j];
        }
    }
    std::cout << "Диапазон значений: [" << min_val << ", " << max_val << "]\n";

    for (int i = 0; i < ROWS; ++i) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    
    std::cout << "Память освобождена.\n";

    return EXIT_SUCCESS;
}