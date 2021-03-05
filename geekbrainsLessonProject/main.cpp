#include <iostream>

using namespace std;

// =======================================
// Task 1: Class Power
// =======================================

class Power {
private:
    float x;
    float y;
    
public:
    void set(float new_x, float new_y) {
        x = new_x;
        y = new_y;
    }
    void calculate() {
        float result = x;
        for (int i = 1; i < y; i++) {
            result *= x;
        }
        
        cout << "calculate(" << x << ", " << y << "): " << result << endl;
    }
};

// =======================================
// Task 2: Class RGBA
// =======================================

class RGBA {
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;
    
public:
    RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : m_red(r), m_green(g), m_blue(b), m_alpha(a) { }
    
    void print() {
        cout << "RGBA DATA: " << endl;
        cout << "R " << int(m_red) << endl;
        cout << "G " << int(m_green) << endl;
        cout << "B " << int(m_blue) << endl;
        cout << "A " << int(m_alpha) << endl;
    }
};

// =======================================
// Task 3: Class Stack
// =======================================

class Stack {
private:
    int array[10];
    int stack_length = 0;
    
public:
    void reset() {
        stack_length = 0;
        for (int i = 0; i < 10; i++) {
            array[i] = 0;
        }
    }
    
    bool push(int value) {
        if (stack_length == 10) return false;
        else {
            array[stack_length] = value;
            stack_length++;
            return true;
        }
    }
    
    void pop() {
        if (stack_length == 0) {
            cout << "error: stack is empty" << endl;
        }
        else {
            array[stack_length] = NULL;
            stack_length--;
        }
    }
    
    void print() {
        cout << "stack: ";
        for (int i = 0; i < stack_length; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    // =======================================
    // Task 1: Execution
    // =======================================
    
    cout << "--- Task 1" << endl;
    Power task1_power;
    task1_power.set(5, 2);
    task1_power.calculate();
    
    task1_power.set(3, 3);
    task1_power.calculate();
    
    task1_power.set(2, 3);
    task1_power.calculate();
    
    cout << endl;

    // =======================================
    // Task 2: Execution
    // =======================================
    
    cout << "--- Task 2" << endl;
    RGBA task2_rgba(5, 2, 31, 248);
    task2_rgba.print();
    
    cout << endl;
    
    // =======================================
    // Task 3: Execution
    // =======================================
    
    cout << "--- Task 3" << endl;
    Stack stack;
    stack.reset();
    stack.print();
        
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
        
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
}
