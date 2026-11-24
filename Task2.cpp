#include <iostream>
using namespace std;
class IntList {
private:
    int* data;
    int count;
    int capacity;
void grow() {
        int oldCap = capacity;
        capacity = capacity * 2;
        int* temp = new int[capacity];

        for (int i = 0; i < count; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        cout << "Resizing: " << oldCap << " -> " << capacity << endl;
    }
public:
    IntList() {
        capacity = 2;
        count = 0;
        data = new int[capacity];
    }
~IntList() {
        delete[] data;
        cout << "IntList memory freed" << endl;
    }
void add(int value) {
        if (count == capacity) {
            grow();
        }
        data[count] = value;
        count++;
    }
int get(int index) {
        if (index < 0 || index >= count) {
            cout << "Invalid index " << index << endl;
            return -1;
        }return data[index];
    }
int size() {
        return count;
    }
void print() {
        cout << "List (" << count << "/" << capacity << "): ";
        for (int i = 0; i < count; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    IntList myList;
    myList.add(10);
    myList.add(20);
    myList.add(30);
    myList.add(40);
    myList.add(50);
    myList.add(60);
    myList.print();
    int a = myList.get(3);
    cout << "Item at 3: " << a << endl;
    int b = myList.get(10);
    cout << "Item at 10: " << b << endl;
    cout << "Size: " << myList.size() << endl;
    return 0;
}