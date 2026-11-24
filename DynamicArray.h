#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;
template <class T>
class DynamicArray {
private:
    T* data;
    int capacity;
    int count;
    T invalidItem;
void grow() {
        int newCap = capacity * 2;
        T* temp = new T[newCap];
        for (int i = 0; i < count; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = newCap;
    }
public:
    DynamicArray(int cap = 2) {
        if (cap < 1) {
            capacity = 1;
        } else {
            capacity = cap;
        }
        data = new T[capacity];
        count = 0;
        invalidItem = T();
    }
~DynamicArray() {
        delete[] data;
    }
void add(T val) {
        if (count == capacity) {
            grow();
        }
        data[count] = val;
        count++;
    }
bool removeAt(int i) {
        if (i < 0 || i >= count) {
            return false;
        }
        for (int j = i; j < count - 1; j++) {
            data[j] = data[j + 1];
        }
        count--;
        return true;
    }
T& operator[](int i) {
        if (i < 0 || i >= count) {
            cout << "Invalid index " << i << endl;
            return invalidItem;
        }
        return data[i];
    }
int size() {
        return count;
    }
bool isEmpty() {
        return count == 0;
    }
};
#endif