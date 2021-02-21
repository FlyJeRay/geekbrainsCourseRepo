#include <iostream>
#include <math.h>

using namespace std;

namespace myNameSpace {

    float * task1_initializeArray(float array[], int arraySize) {
        for (int i = 0; i < arraySize; i++) {
            array[i] = rand() % 100 + (-50);
        }
    
        return array;
    }

    void task1_printArray(float array[], int arraySize) {
        cout << "----- array printing" << endl;
        for (int i = 0; i < arraySize; i++) {
            cout << "array element " << i << ": " << array[i] << endl;
        }
    }


    void task1_sortArray(float array[], int arraySize) {
        cout << "----- array sorting" << endl;
    
        int positiveNumbers = 0;
        int negativeNumbers = 0;
    
        for (int i = 0; i < arraySize; i++) {
            if (array[i] < 0) negativeNumbers++;
            else if (array[i] > 0) positiveNumbers++;
        }
    
        cout << "positive numbers: " << positiveNumbers << endl;
        cout << "negative numbers: " << negativeNumbers << endl;
    }
}
