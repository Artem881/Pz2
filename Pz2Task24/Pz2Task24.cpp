#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <windows.h> 

using namespace std;

int* form_mas(int size) {
    if (size <= 0) return nullptr;
    return new int[size];
}

void init_mas(int* mas, int size) {
    if (!mas) return;
    for (int i = 0; i < size; i++) {
        mas[i] = rand() % 30 - 15;
    }
}

void print_mas(const int* mas, int size) {
    if (!mas || size <= 0) {
        cout << "Масив порожній!" << endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int* del_min_mas(int* mas, int& size) {
    if (!mas || size <= 0) {
        cout << "Помилка: Спроба видалення з порожнього масиву!" << endl;
        return mas;
    }

    int min_val = mas[0];
    for (int i = 1; i < size; i++) {
        if (mas[i] < min_val) min_val = mas[i];
    }
    cout << "Мінімальне значення для видалення: " << min_val << endl;

    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] != min_val) new_size++;
    }

    if (new_size == 0) {
        cout << "Попередження: Усі елементи були мінімальними. Масив тепер порожній." << endl;
        delete[] mas;
        size = 0;
        return nullptr;
    }

    int* new_mas = form_mas(new_size);
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] != min_val) {
            new_mas[idx++] = mas[i];
        }
    }

    delete[] mas;
    size = new_size;
    return new_mas;
}

int** form_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return nullptr;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void init_matrix(int** matrix, int rows, int cols) {
    if (!matrix) return;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
}

void print_matrix(int** matrix, int rows, int cols) {
    if (!matrix || rows <= 0 || cols <= 0) {
        cout << "Матриця порожня!" << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void free_matrix(int** matrix, int rows) {
    if (!matrix) return;
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int** del_row_with_zero(int** matrix, int& rows, int cols) {
    if (!matrix || rows <= 0) {
        cout << "Помилка: Спроба видалення з порожньої матриці!" << endl;
        return matrix;
    }

    int target_row = -1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                target_row = i;
                break;
            }
        }
        if (target_row != -1) break;
    }

    if (target_row == -1) {
        cout << "Рядки з нульовими елементами не знайдені. Матриця без змін." << endl;
        return matrix;
    }

    cout << "Видаляється рядок з індексом: " << target_row << endl;

    if (rows == 1) {
        free_matrix(matrix, rows);
        rows = 0;
        return nullptr;
    }

    int** new_matrix = new int* [rows - 1];
    int current_new_row = 0;

    for (int i = 0; i < rows; i++) {
        if (i == target_row) {
            delete[] matrix[i];
        }
        else {
            new_matrix[current_new_row++] = matrix[i];
        }
    }

    delete[] matrix;
    rows--;
    return new_matrix;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned int>(time(0)));

    int* odnomir_mas = nullptr;
    int odnomir_size = 0;

    int** dvomir_matrix = nullptr;
    int matrix_rows = 0, matrix_cols = 0;

    int menu_choice;

    do {
        cout << "\n================ ТЕКСТОВЕ МЕНЮ ================" << endl;
        cout << "1. Сформувати та ініціалізувати одновимірний масив" << endl;
        cout << "2. Друкувати одновимірний масив" << endl;
        cout << "3. Видалити мінімальні елементи з одновимірного масиву" << endl;
        cout << "4. Сформувати та ініціалізувати двовимірну матрицю" << endl;
        cout << "5. Друкувати двовимірну матрицю" << endl;
        cout << "6. Видалити перший рядок з нулем із матриці" << endl;
        cout << "7. Вихід" << endl;
        cout << "Оберіть пункт: ";
        cin >> menu_choice;

        switch (menu_choice) {
        case 1:
            if (odnomir_mas) delete[] odnomir_mas;
            cout << "Введіть розмір одновимірного масиву: ";
            cin >> odnomir_size;
            odnomir_mas = form_mas(odnomir_size);
            init_mas(odnomir_mas, odnomir_size);
            cout << "Масив створено." << endl;
            break;

        case 2:
            cout << "Поточний одновимірний масив:" << endl;
            print_mas(odnomir_mas, odnomir_size);
            break;

        case 3:
            odnomir_mas = del_min_mas(odnomir_mas, odnomir_size);
            break;

        case 4:
            if (dvomir_matrix) free_matrix(dvomir_matrix, matrix_rows);
            cout << "Введіть кількість рядків: "; cin >> matrix_rows;
            cout << "Введіть кількість стовпців: "; cin >> matrix_cols;
            dvomir_matrix = form_matrix(matrix_rows, matrix_cols);
            init_matrix(dvomir_matrix, matrix_rows, matrix_cols);
            cout << "Матрицю створено." << endl;
            break;

        case 5:
            cout << "Поточна двовимірна матриця:" << endl;
            print_matrix(dvomir_matrix, matrix_rows, matrix_cols);
            break;

        case 6:
            dvomir_matrix = del_row_with_zero(dvomir_matrix, matrix_rows, matrix_cols);
            break;

        case 7:
            cout << "Завершення роботу програми..." << endl;
            break;

        default:
            cout << "Невірний пункт меню! Спробуйте ще раз." << endl;
        }
    } while (menu_choice != 7);

    if (odnomir_mas) delete[] odnomir_mas;
    if (dvomir_matrix) free_matrix(dvomir_matrix, matrix_rows);

    return 0;
}