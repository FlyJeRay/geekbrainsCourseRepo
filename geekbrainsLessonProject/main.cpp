#include <iostream>

using namespace std;
bool isLeapYear(int year);

int main(){
    
    // =============================================
    // Домашнее задание №1
    // =============================================
    
    int hw1_number;
    
    cout << "enter number" << endl;
    cin >> hw1_number;
    
    if (hw1_number <= 20 && hw1_number >= 10) {
        cout << "hw1-true" << endl;
    }
    else {
        cout << "hw1-false" << endl;
    }
    
    // =============================================
    // Домашнее задание №2
    // =============================================
    
    const int hw2_number_1 = 5;
    const int hw2_number_2 = 5;
    
    if ((hw2_number_1 == 10 && hw2_number_2 == 10) || hw2_number_1 + hw2_number_2 == 10) {
        cout << "hw2-true" << endl;
    }
    else {
        cout << "hw2-false" << endl;
    }
    
    // =============================================
    // Домашнее задание №3
    // =============================================
    
    for (int i = 0; i < 50; i++) {
        if (i % 2 != 0) {
            cout << to_string(i) + " ";
        }
    }
    
    cout << endl;
    
    // =============================================
    // Домашнее задание со звёздочкой
    // =============================================
    
    // Результат. Изначально стоит true и *если* окажется,
    // что число не простое, изменится на false
    bool hwStar_result = true;
    int hwStar_number;
    
    cout << "enter number" << endl;
    cin >> hwStar_number;
    
    for (int i = 1; i < hwStar_number; i++) {
        if (i != 1 && i != hwStar_number) {
            if (hwStar_number % i == 0) hwStar_result = false;
        }
    }
    
    if (hwStar_result) cout << "hwStar-true" << endl;
    else cout << "hwStar-false" << endl;
    
    // =============================================
    // Домашнее задание с двумя звёздочками
    // =============================================
    
    int hw2Star_year;
    cout << "write the year" << endl;
    cin >> hw2Star_year;
    
    if (hw2Star_year < 1 || hw2Star_year > 3000) {
        cout << "invalid year" << endl;
    }
    
    // Использование функции в нижней части кода (строки 90-96)
    bool hw2Star_result = isLeapYear(hw2Star_year);
    
    if (hw2Star_result) cout << "hw2Star-true" << endl;
    else cout << "hw2Star-false" << endl;
}

// Функция для домашнего задания с двумя звёздочками
bool isLeapYear(int year) {
    if (year % 400 == 0) return true;
    else if (year % 100 == 0) return false;
    else if (year % 4 == 0) return true;
    else return false;
}
