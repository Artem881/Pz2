#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>
using namespace std;

const int MAX_STRING_SIZE = 300;

void process_string(const char* source, char* result) {
    char temp[MAX_STRING_SIZE];
    strcpy(temp, source);

    result[0] = '\0';

    char* token = strtok(temp, " ");
    int word_counter = 1; 

    while (token != nullptr) {
        if (word_counter % 2 != 0) {
            if (strlen(result) > 0) {
                strcat(result, " ");
            }
            strcat(result, token); 
        }

        word_counter++;          
        token = strtok(nullptr, " "); 
    }
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    char input_str[MAX_STRING_SIZE];
    char result_str[MAX_STRING_SIZE];

    cout << "Введіть рядок символів з клавіатури:" << endl;
    cin.getline(input_str, MAX_STRING_SIZE);

    if (strlen(input_str) == 0) {
        cout << "Помилка: Ви ввели порожній рядок!" << endl;
        return 1;
    }

    process_string(input_str, result_str);

    cout << "\n--- Результати обробки рядка ---" << endl;
    cout << "Початковий рядок: " << input_str << endl;
    cout << "Результуючий рядок (без парних слів): " << result_str << endl;

    return 0;
}