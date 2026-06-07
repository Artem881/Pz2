#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
#include <windows.h> 
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

void printMatrix(const int matrix[MAX_ROWS][MAX_COLS], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned int>(time(0)));

    int n;
    cout << "Введіть розмір квадратної матриці n x n (менше " << MAX_ROWS << "): ";
    cin >> n;

    if (n <= 0 || n >= MAX_ROWS) {
        cout << "Невірний розмір матриці!" << endl;
        return 1;
    }

    int matrix[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100 - 50;
        }
    }

    cout << "\nЗгенерована матриця чисел:" << endl;
    printMatrix(matrix, n);

    int count = 0;
    cout << "\nЕлементи головної діагоналі: ";
    for (int i = 0; i < n; i++) {
        cout << matrix[i][i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        int element = matrix[i][i];
        if (element < 0 && element % 3 != 0) {
            count++;
        }
    }

    cout << "\n--- Результати виконання ---" << endl;
    cout << "Кількість негативних і не кратних 3 чисел на головній діагоналі: " << count << endl;

    return 0;
}