#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h> 

using namespace std;

const int MAX_SIZE = 100;

void printArray(const int mas[], int n) {
    if (n == 0) {
        cout << "Масив порожній!" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned int>(time(0)));

    int n;
    cout << "Введіть розмір масиву n < " << MAX_SIZE << ": ";
    cin >> n;

    if (n <= 0 || n >= MAX_SIZE) {
        cout << "Невірний розмір масиву!" << endl;
        return 1;
    }

    int mas[MAX_SIZE];

    for (int i = 0; i < n; i++) {
        mas[i] = rand() % 100 - 50;
    }

    cout << "\n1-2) Початковий масив:" << endl;
    printArray(mas, n);

    if (n > 0) {
        int min_val = mas[0];
        for (int i = 1; i < n; i++) {
            if (mas[i] < min_val) {
                min_val = mas[i];
            }
        }
        cout << "\nМінімальний елемент для видалення: " << min_val << endl;

        for (int i = 0; i < n; i++) {
            if (mas[i] == min_val) {
                for (int j = i; j < n - 1; j++) {
                    mas[j] = mas[j + 1];
                }
                n--;
                i--;
            }
        }
        cout << "3-4) Масив після видалення мінімальних елементів:" << endl;
        printArray(mas, n);
    }

    for (int i = 0; i < n; i++) {
        if (mas[i] % 2 == 0) {
            if (n >= MAX_SIZE) {
                cout << "\nПомилка: Переповнення масиву, вставка неможлива!" << endl;
                break;
            }
            for (int j = n; j > i; j--) {
                mas[j] = mas[j - 1];
            }
            mas[i] = 0;
            n++;
            i++;
        }
    }
    cout << "\n5-6) Масив після додавання 0 перед парними елементами:" << endl;
    printArray(mas, n);

    int half = n / 2;
    int second_half_start = (n % 2 == 0) ? half : half + 1;
    for (int i = 0; i < half; i++) {
        swap(mas[i], mas[second_half_start + i]);
    }
    cout << "\n7-8) Масив після перестановки половин:" << endl;
    printArray(mas, n);

    int search_key;
    cout << "\n9) Введіть елемент для лінійного пошуку: ";
    cin >> search_key;

    int linear_comparisons = 0;
    int linear_idx = -1;
    for (int i = 0; i < n; i++) {
        linear_comparisons++;
        if (mas[i] == search_key) {
            linear_idx = i;
            break;
        }
    }
    if (linear_idx != -1) {
        cout << "10) Елемент знайдено на індексі: " << linear_idx << endl;
    }
    else {
        cout << "10) Елемент не знайдено!" << endl;
    }
    cout << "Кількість порівнянь: " << linear_comparisons << endl;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (mas[j] < mas[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(mas[i], mas[min_idx]);
        }
    }
    cout << "\n11-12) Масив після сортування методом простого вибору:" << endl;
    printArray(mas, n);

    cout << "\n13) Введіть елемент для бінарного пошуку: ";
    cin >> search_key;

    int left = 0, right = n - 1;
    int binary_comparisons = 0;
    int binary_idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        binary_comparisons++;

        if (mas[mid] == search_key) {
            binary_idx = mid;
            break;
        }
        binary_comparisons++;
        if (mas[mid] < search_key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    if (binary_idx != -1) {
        cout << "14) Елемент знайдено на індексі: " << binary_idx << endl;
    }
    else {
        cout << "14) Елемент не знайдено!" << endl;
    }
    cout << "Кількість порівнянь: " << binary_comparisons << endl;

    return 0;
}
