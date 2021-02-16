#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int task1_getNewArraySize();
int * task1_initializeAnArray(int * array, int arraySize);

int ** task2_initializeAnArray(int ** array);

void task3_initializeFiles();

void task4_connectFiles();
string task4_copyFileContent(string fileName, string previousContent);

void task5_start();
bool task5_checkFileContent(string fileName, string checkWord);

void printArray(int array[], int arraySize);
void print2dArray(int ** array);


int main(){
    cout << "Task 1 ==========================" << endl;
    
    int task1_arraySize = task1_getNewArraySize();
    int * task1_array = nullptr;
    task1_array = task1_initializeAnArray(task1_array, task1_arraySize);
    printArray(task1_array, task1_arraySize);
    
    cout << endl << "Task 2 ==========================" << endl;
    
    int ** task2_array = nullptr;
    task2_array = task2_initializeAnArray(task2_array);
    print2dArray(task2_array);
    delete[] task2_array;
    
    cout << endl << "Task 3 ==========================" << endl;
    task3_initializeFiles();
    
    cout << endl << "Task 4 ==========================" << endl;
    task4_connectFiles();
    
    cout << endl << "Task 5 ==========================" << endl;
    task5_start();
}

// ====================================
// Функции для задания 1
// ====================================

int task1_getNewArraySize() {
    int task1_arraySize;
    cout << "   Массив какого размера вы хотите создать?" << endl;
    cin >> task1_arraySize;
    
    return task1_arraySize;
}

int * task1_initializeAnArray(int * array, int arraySize) {
    array = new int[arraySize];
    
    int a = 1;
    
    for (int i = 0; i < arraySize; i++) {
        array[i] = a;
        a *= 2;
    }
    
    return array;
}

// ====================================
// Функция для задания 2
// ====================================

int ** task2_initializeAnArray(int ** array) {
    array = new int * [4];
    
    for (int i = 0; i < 4; i++) {
        array[i] = new int[4];
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            array[i][j] = rand() % 100;
        }
    }
    
    return array;
}

// ====================================
// Функция для задания 3
// ====================================

void task3_initializeFiles() {
    string fileName_1, fileName_2;
    
    cout << "   Как вы хотите назвать ваш первый файл?" << endl;
        cin >> fileName_1;
    cout << "   Отлично. А как вы хотите назвать ваш второй файл?" << endl;
        cin >> fileName_2;
    
    ofstream first_file(fileName_1);
    first_file << "Text of the first text file, made by script (by Daniil Antoniuk)" << endl;
    first_file.close();
    
    ofstream second_file(fileName_2);
    second_file << "Text of the second text file, made by script (by Daniil Antoniuk)" << endl;
    second_file.close();
}

// ====================================
// Функции для задания 4
// ====================================

void task4_connectFiles() {
    string fileName_1, fileName_2, fileName_final;
    
    cout << "   Введите название первого файла" << endl;
    cin >> fileName_1;
    
    cout << "   Введите название второго файла" << endl;
    cin >> fileName_2;
    
    cout << "   Введите название файла, в котором должны быть данные двух предыдущих файлов" << endl;
    cin >> fileName_final;
    
    string filesContent = "";
    
    filesContent = task4_copyFileContent(fileName_1, filesContent);
    filesContent += "\n\n";
    filesContent = task4_copyFileContent(fileName_2, filesContent);
    
    ofstream finalFile(fileName_final);
    finalFile << filesContent << endl;
    finalFile.close();
}

string task4_copyFileContent(string fileName, string previousContent) {
    ifstream file(fileName);
    previousContent += "------- Содержимое " + fileName + ": \n";
    if (file.is_open()) {
        const int size = 255;
        char characters[size];
        while (!file.eof())
        {
            file.getline(characters, size);
            previousContent += characters;
        }
    }
    else {
        cout << "   Ошибка с чтением файла " + fileName << endl;
    }
    
    file.close();
    return previousContent;
}

// ====================================
// Функции для задания 5
// ====================================

void task5_start() {
    string fileName, checkWord;
    
    cout << "   Введите название файла, который вы хотите проверить." << endl;
    cin >> fileName;
    
    cout << "   Введите слово, на наличие которого вы хотите проверить файл" << endl;
    cin >> checkWord;
    
    if (task5_checkFileContent(fileName, checkWord)) {
        cout << "Слово " + checkWord + " было найдено в файле " + fileName;
    }
    else {
        cout << "Слово " + checkWord + " не было найдено в файле " + fileName << endl;
    }
}

bool task5_checkFileContent(string fileName, string word) {
    ifstream file(fileName);
    
    if (file.is_open()) {
        const int size = 255;
        char characters[size];
        while (!file.eof())
        {
            file.getline(characters, size);
            string line = characters;
            // Признаюсь, тут помог stackoverflow
            // Но, поидее, такой метод использовать и надо?
            // Он вроде как самый простой
            if (line.find(word) != string::npos) return true;
        }
    }
    else {
        cout << "   Ошибка с чтением файла " + fileName << endl;
    }
    
    return false;
}

// ====================================
// Общие функции
// ====================================

void printArray(int array[], int arraySize) {
    cout << "array: ";
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void print2dArray(int ** array) {
    cout << "array: " << endl;
    
    for (int i = 0; i < 4; i++) {
        cout << "   ";
        for (int j = 0; j < 4; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
