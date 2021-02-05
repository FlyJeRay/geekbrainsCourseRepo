#include <iostream>

using namespace std;

int main(){
    // ====================================
    // Домашнее задание №1
    // ====================================
    
    const int a = 1;
    const int b = 5;
    const int c = 7;
    const int d = 9;
    
    float result = a * (b + (float(c) / d));
    cout << result << endl;
        // 5.77778
    
    // ====================================
    // Домашнее задание №2
    // ====================================
    
    int number;
    
    cout << "Запишите целое число: " << endl;
    cin >> number;
    
    number <= 21 ?
    cout << to_string(number - 21) << endl :
    cout << to_string(2 * (number - 21)) << endl;
    
    // ====================================
    // Домашнее задание со звёдочкой
    // ====================================
    
    int array[3][3][3] = {
        { {1, 2, 3},    {4, 5, 6},    {7, 8, 9} },
        { {10, 11, 12}, {13, 14, 15}, {16, 17, 18} },
        { {19, 20, 21}, {22, 23, 24}, {25, 26, 27} }
    };
    
    int * pointer;
    pointer = & array[1][1][1];
    
    cout << *pointer << endl;
        // Вывод - 14
    
    // ====================================
    // Домашнее задание с двумя звёздочками
    // ====================================
    
    extern int add_a;
    extern int add_b;
    extern int add_c;
    extern int add_d;
    
    float result_2 = add_a * (add_b + (float(add_c) / add_d));
    cout << result_2 << endl;
        // 3.71429
}
