#include <iostream>
#include <string>
using namespace std;
template <class T>
class Stack {
private:
    T* a;
    int top;
    int cap;
public:
    Stack(int c = 5) {
        cap = c;
        a = new T[cap];
        top = -1;
    }
~Stack() {
        delete[] a;
    }
bool isEmpty() {
        if (top == -1)
            return true;
        return false;
    }
bool isFull() {
        if (top == cap - 1)
            return true;
        return false;
    }
int size() {
        return top + 1;
    }
void push(T val) {
        if (isFull()) {
            cout << "Stack is full, cannot push " << val << endl;
            return;
        }
        top++;
        a[top] = val;
    }
T pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        T x = a[top];
        top--;
        return x;
    }
T peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return T();
        }
        return a[top];
    }
void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Stack<int> st1(4);
    st1.push(10);
    st1.push(20);
    st1.push(30);
    st1.display();
    cout << "Top: " << st1.peek() << endl;
    cout << "Pop: " << st1.pop() << endl;
    st1.display();
    cout << "Size: " << st1.size() << endl;
    Stack<string> st2(3);
    st2.push("Ali");
    st2.push("Sara");
    st2.push("Zain");
    st2.push("Bilal");
    st2.display();
    cout << "Pop: " << st2.pop() << endl;
    cout << "Pop: " << st2.pop() << endl;
    cout << "Pop: " << st2.pop() << endl;
    st2.pop();
    return 0;
}