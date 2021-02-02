#include <iostream>

int main(){
    //
    // Домашнее задание, часть 1
    //
    
    short int number = 12;
    int integer = 583;
    long long numberTwo = 123'432'765;
    char character = 'A';
    bool boolean = true;
    double p = 3.14;
    
    enum symbols { X, O };
    symbols symbolArray[5] = { X, O, O, X, O };
    
    //
    // Домашнее задание, одна звёздочка
    //
    
    struct ticTacToeField {
        int fieldHeight; // Высота игрового поля
        int fieldWidht; // Ширина игрового поля
        int comboForWin; // Сколько крестиков или ноликов нужно собрать в ряд для победы
    };
    
    //
    // Домашнее задание, две звёздочки
    //
    
    union testUnion {
        int unInteger;
        float unFloat;
        char unChar;
    };
    
    struct homeworkStructure {
        testUnion _union;
        
        unsigned short isInt : 1;
        unsigned short isFloat : 1;
        unsigned short isChar : 1;
    };
}
