#include <iostream>

using namespace std;

// ===================================================
// Объявление функций
// ===================================================

void task1(double array[], int arraySize);
void task2(int array[], int arraySize);
void task3(int oldArray[8]);
void task4(int array[], int n, int arraySize);
void task5(int array[], int arraySize);

void arrayShiftRight(int array[], int arraySize);
void arrayShiftLeft(int array[], int arraySize);

void printArray(int array[], int arraySize);
void printArray(double array[], int arraySize);

// ===================================================
// Основная функция
// ===================================================

int main(){
    cout << endl << "task 1 ============================" << endl;
    
    double task1_array[] = { 1.52, 23.53, 75.12, 3.32, 9.8, 1.2 };
    task1(task1_array, 6);
    
    cout << endl << "task 2 ============================" << endl;
    
    int task2_array[] = { 0, 1, 0, 0, 0, 1, 1, 0, 0, 1 };
    task2(task2_array, 10);
    
    cout << endl << "task 3 ============================" << endl;
    
    int task3_oldArray[8];
    task3(task3_oldArray);
    
    cout << endl << "task 4 ============================" << endl;
    
    int task4_array[] = { 0, 1, 2, 3, 4, 5 };
    int task4_array2[] = { 0, 1, 2, 3, 4 };
    int task4_array3[] = { 0, 1, 2 };
    
    task4(task4_array, 3, 6);
    task4(task4_array2, -2, 5);
    task4(task4_array3, 3, 3);
    
    cout << endl << "task 5 ============================" << endl;
    
    int task5_array1[] = { 1, 1, 1, 2, 1 };
    int task5_array2[] = { 2, 1, 1, 2, 1 };
    int task5_array3[] = { 10, 1, 2, 3, 4 };
    int task5_array4[] = { 5, 1, 3, 1 };
    int task5_array5[] = { 3, 2, 3, 8, 0 };
    
    task5(task5_array1, 5);
    task5(task5_array2, 5);
    task5(task5_array3, 5);
    task5(task5_array4, 4);
    task5(task5_array5, 5);
}

// ===================================================
// Функция для задания 1
// ===================================================

void task1(double array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ===================================================
// Функция для задания 2
// ===================================================

void task2(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == 0) array[i] = 1;
        else if (array[i] == 1) array[i] = 0;
        // На всякий случай - проверка числа
        else cout << "warning -- wrong number on array[" << i << "]" << endl;
    }
    
    printArray(array, arraySize);
}

// ===================================================
// Функция для задания 3
// ===================================================

void task3(int oldArray[8]) {
    int task3_newArray[8] = { 1, 4, 7, 10, 13, 16, 19, 22 };
    
    for (int i = 0; i < 8; i++) {
        oldArray[i] = task3_newArray[i];
    }
    
    printArray(oldArray, 8);
}

// ===================================================
// Функции для задания 4
// ===================================================

void task4(int array[], int n, int arraySize) {
    cout << "/// starting task 4" << endl;
    
    // Проверка того, в какую сторону будет смещение,
    // и будет ли оно идти вообще - если сместить массив
    // нужно на n-ное количество кругов или на 0,
    // операции смещения не нужны вовсе.
    
    if (n % arraySize == 0 || n == 0) {
        cout << "   array stays the same" << endl;
        return;
    }
    
    // У меня почему-то ни в какую не получалось сделать
    // смещение сразу на несколько мест,
    // так что я решил просто сделать цикличные смещения
    // по одному месту
    
    else if (n > 0) {
        for (int i = 0; i <= n; i++) arrayShiftLeft(array, arraySize);
    }
    else if (n < 0) {
        for (int i = n; i < 0; i++)  arrayShiftRight(array, arraySize);
    }
    
    cout << "   result = ";
    printArray(array, arraySize);
}

void arrayShiftLeft(int array[], int arraySize) {
    int savedNumber = array[0];
    
    for (int i = 0; i < arraySize - 1; i++) {
        array[i] = array[i + 1];
    }
    
    array[arraySize - 1] = savedNumber;
    printArray(array, 6);
}

void arrayShiftRight(int array[], int arraySize) {
    int savedNumber = array[arraySize - 1];
    
    for (int i = arraySize - 1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    
    array[0] = savedNumber;
    printArray(array, 5);
}

// ===================================================
// Функция для задания 5
// ===================================================

void task5(int array[], int arraySize) {
    bool result = false;
    
    int sum1 = 0;
    int sum2 = 0;
    
    for (int i = 0; i < arraySize; i++) {
        // Берём сумму всех символов первой половины
        sum1 = 0;
        for (int j = 0; j <= i; j++) {
            sum1 += array[j];
        }
        
        // Берём сумму всех символов второй половины
        sum2 = 0;
        for (int k = i + 1; k < arraySize; k++) {
            sum2 += array[k];
        }
        
        // Если сумма двух половин равна - указываем это и прерываем цикл
        if (sum1 == sum2) {
            result = true;
            break;
        }
    }
    
    if (result == true) cout << "true / " << sum1 << " + " << sum2 << endl;
    else cout << "false" << endl;
}

// ===================================================
// Функции для быстрой печати массивов (DRY, как никак)
// ===================================================

void printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    
    cout << endl;
}

void printArray(double array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    
    cout << endl;
}
