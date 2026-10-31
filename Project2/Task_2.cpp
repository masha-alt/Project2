#include <iostream>
#include <limits>
#include <iomanip>

void clearInput2() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void showInfo2() {
    std::cout << "Задание 2\n";
    std::cout << "Суть задания: Найти произведение положительных элементов,\n";
    std::cout << "расположенных ниже главной диагонали статической матрицы MxN.\n";
    std::cout << "Максимальный поддерживаемый размер матрицы: 50x50.\n";
    std::cout << "Выполнила: Бацкель Мария\n";
    std::cout << "Группа: 653501\n";
    std::cout << "Вариант: 4\n";
}

bool calculateProductBelowDiagonal(const int matrix[][50], int rows, int cols, long long& product) {
    product = 1;
    bool has_positive = false;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > j && matrix[i][j] > 0) {
                product *= matrix[i][j];
                has_positive = true;
            }
        }
    }
    return has_positive;
}

void processMatrix() {
    const int MAX_ROWS = 50;
    const int MAX_COLS = 50;
    int M = 0, N = 0;

    while (true) {
        std::cout << "\nВведите количество строк матрицы M (от 1 до " << MAX_ROWS << "): ";
        if (std::cin >> M && M > 0 && M <= MAX_ROWS) break;
        std::cout << "Ошибка! M должно быть целым числом в заданном диапазоне.\n";
        clearInput2();
    }

    while (true) {
        std::cout << "Введите количество столбцов матрицы N (от 1 до " << MAX_COLS << "): ";
        if (std::cin >> N && N > 0 && N <= MAX_COLS) break;
        std::cout << "Ошибка! N должно быть целым числом в заданном диапазоне.\n";
        clearInput2();
    }

    int matrix[50][50];

    std::cout << "\nВведите элементы матрицы размером " << M << "x" << N << ":\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            while (true) {
                std::cout << "Матрица[" << i << "][" << j << "]: ";
                if (std::cin >> matrix[i][j]) break;
                std::cout << "Некорректный ввод! Введите целое число.\n";
                clearInput2();
            }
        }
    }

    std::cout << "\nИсходные данные (Матрица):\n";
    for (int i = 0; i < M; i++) {
        std::cout << "  "; 
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(1) << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }


    long long result_product = 0;

    if (calculateProductBelowDiagonal(matrix, M, N, result_product)) {
        std::cout << "\nРезультат: Произведение положительных элементов ниже главной диагонали = " << result_product << "\n";
    }
    else {
        std::cout << "\nРезультат: Ниже главной диагонали нет положительных элементов.\n";
    }
}

int main() {
    int choice = 0;

    while (true) {
        std::cout << "1. Показать информацию о задании\n";
        std::cout << "2. Выполнить расчет матрицы\n";
        std::cout << "3. Выйти из программы\n";
        std::cout << "Выберите действие: ";

        if (!(std::cin >> choice)) {
            std::cout << "\nНекорректный ввод! Пожалуйста, введите число.\n";
            clearInput2();
            continue;
        }

        switch (choice) {
        case 1:
            showInfo2();
            break;
        case 2:
            processMatrix();
            break;
        case 3:
            std::cout << "\nЗавершение работы программы. До свидания!\n";
            return 0;
        default:
            std::cout << "\nПункта с таким номером нет. Попробуйте еще раз.\n";
            break;
        }
    }
    return 0;
}
