#include <iostream>
#include "addition.h"

#define task2(x, y) (y > 0 ? (x >= 0 && x < y ? true : false) : (x <= 0 && x > y ? true : false))
#define SwapINT(x, y) int temp = x; x = y; y = temp;
#define task3_arraySize 5

using namespace std;
using namespace myNameSpace;

#pragma pack(push, 1)
struct Employee {
    string name;
    short age;
    int id;
    double salary;
};
#pragma pack(pop)

void task1_procedure(float array[], int arraySize);
void task2_procedure(int x, int y);
void task3_procedure(int array[]);
void task3_printArray(int array[], int arraySize);
void task4_procedure(Employee employee);

int main() {
    cout << "--------------- TASK 1" << endl << endl;
    
    const int task1_array1_size = 2;
    const int task1_array2_size = 5;
    const int task1_array3_size = 3;
    
    float task1_array1[task1_array1_size];
    float task1_array2[task1_array2_size];
    float task1_array3[task1_array3_size];
    
    task1_procedure(task1_array1, task1_array1_size);
    cout << endl;
    task1_procedure(task1_array2, task1_array2_size);
    cout << endl;
    task1_procedure(task1_array3, task1_array3_size);
    cout << endl;

    cout << endl << "--------------- TASK 2" << endl << endl;
    
    task2_procedure(5, 15);
    task2_procedure(15, 5);
    task2_procedure(-2, -10);
    task2_procedure(-10, -2);
    
    cout << endl <<"--------------- TASK 3" << endl << endl;
    
    int task3_array[task3_arraySize];
    task3_procedure(task3_array);
    
    cout << endl << "--------------- TASK 4" << endl << endl;
    
    Employee task4_employee;
    task4_procedure(task4_employee);
}

// ========================================================
// Task 1
// ========================================================

void task1_procedure(float array[], int arraySize) {
    array = task1_initializeArray(array, arraySize);
    task1_printArray(array, arraySize);
    task1_sortArray(array, arraySize);
}

// ========================================================
// Task 2
// ========================================================

void task2_procedure(int x, int y) {
    if (task2(x, y)) {
        cout << "(" << x << ", " << y << ") --- true" << endl;
    }
    else {
        cout << "(" << x << ", " << y << " ) --- false" << endl;
    }
}

// ========================================================
// Task 3
// ========================================================

void task3_procedure(int array[]) {
    for (int i = 0; i < task3_arraySize; i++) {
        int newValue;
        
        cout << "write down the value of array[" << i << "]" << endl;
        cin >> newValue;
        array[i] = newValue;
    }
    
    for (int i = 0; i < task3_arraySize; i++) {
        for (int j = 0; j < task3_arraySize; j++) {
            if (array[j] > array[j + 1]) {
                SwapINT(array[j], array[j + 1]);
            }
        }
    }
    
    cout << endl;
    task3_printArray(array, task3_arraySize);
}

void task3_printArray(int array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
}

// ========================================================
// Task 4
// ========================================================

void task4_procedure(Employee employee) {
    Employee * ptr = new Employee(employee);
    *ptr = { "John", 21, 6546, 1000.00 };
    employee = *ptr;
    
    cout << "Structure: " << endl;
    cout << "   Name: " << employee.name << endl;
    cout << "   Age: " << employee.age << endl;
    cout << "   ID: " << employee.id << endl;
    cout << "   Salary: " << employee.salary << endl << endl;
    
    cout << "Structure Size: " << sizeof(employee) << endl << endl;
    
    delete ptr;
}
