#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <windows.h> 

using namespace std;

void printArray(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "Масив порожній!" << endl;
        return;
    }
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    srand(static_cast<unsigned int>(time(0)));

    int n;
    cout << "Введіть розмір масиву (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Розмір масиву повинен бути більшим за 0!" << endl;
        return 1;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 50 + 1;
    }

    cout << "\n--- Початковий масив: ---" << endl;
    printArray(arr);

    if (!arr.empty()) {
        int min_val = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] < min_val) {
                min_val = arr[i];
            }
        }
        cout << "Мінімальне значення для видалення: " << min_val << endl;

        vector<int> filtered_arr;
        for (int num : arr) {
            if (num != min_val) {
                filtered_arr.push_back(num);
            }
        }
        arr = filtered_arr;
        cout << "Масив після видалення мінімальних елементів:" << endl;
        printArray(arr);
    }

    vector<int> added_arr;
    for (int num : arr) {
        if (num % 2 == 0) {
            added_arr.push_back(0);
        }
        added_arr.push_back(num);
    }
    arr = added_arr;
    cout << "Масив після додавання 0 перед парними елементами:" << endl;
    printArray(arr);

    int size = arr.size();
    int half = size / 2;
    int second_half_start = (size % 2 == 0) ? half : half + 1;

    for (int i = 0; i < half; i++) {
        swap(arr[i], arr[second_half_start + i]);
    }
    cout << "Масив після перестановки половин:" << endl;
    printArray(arr);

    int search_key;
    cout << "\nВведіть елемент для лінійного пошуку: ";
    cin >> search_key;

    int linear_comparisons = 0;
    bool found_linear = false;
    int linear_idx = -1;

    for (int i = 0; i < arr.size(); i++) {
        linear_comparisons++;
        if (arr[i] == search_key) {
            found_linear = true;
            linear_idx = i;
            break;
        }
    }

    if (found_linear) {
        cout << "Елемент знайдено на індексі: " << linear_idx << endl;
    }
    else {
        cout << "Елемент не знайдено!" << endl;
    }
    cout << "Кількість порівнянь при лінійному пошуку: " << linear_comparisons << endl;

    int n_sort = arr.size();
    for (int i = 0; i < n_sort - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n_sort; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
    cout << "\nМасив після сортування методом простого вибору:" << endl;
    printArray(arr);

    cout << "\nВведіть елемент для бінарного пошуку: ";
    cin >> search_key;

    int left = 0;
    int right = arr.size() - 1;
    int binary_comparisons = 0;
    bool found_binary = false;
    int binary_idx = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        binary_comparisons++;

        if (arr[mid] == search_key) {
            found_binary = true;
            binary_idx = mid;
            break;
        }

        binary_comparisons++;
        if (arr[mid] < search_key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (found_binary) {
        cout << "Елемент знайдено на індексі: " << binary_idx << endl;
    }
    else {
        cout << "Елемент не знайдено!" << endl;
    }
    cout << "Кількість порівнянь при бінарному пошуку: " << binary_comparisons << endl;

    return 0;
}