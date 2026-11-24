#include <iostream>
#include <string>
using namespace std;
template <class T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <class T>
T findMax(T arr[], int n) {
    T mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}

template <class T>
int countValue(T arr[], int n, T value) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cnt++;
        }
    }
    return cnt;
}
template <class T>
int search(T arr[], int n, T value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}
int main() {
    int a[] = {4, 9, 2, 9, 7};
    printArray(a, 5);
    cout << "Max: " << findMax(a, 5);
    cout << ", count of 9: " << countValue(a, 5, 9) << endl;
    double b[] = {31.5, 28, 35.2};
    printArray(b, 3);
    cout << "Max: " << findMax(b, 3) << endl;
    string c[] = {"Ali", "Sara", "Zain", "Sara"};
    printArray(c, 4);
    cout << "Max: " << findMax(c, 4);
    cout << ", Sara found at index " << search(c, 4, string("Sara")) << endl;
    char d[] = {'B', 'A', 'C', 'A', 'A'};
    printArray(d, 5);
    cout << "Count of A: " << countValue(d, 5, 'A');
    cout << ", D found at index " << search(d, 5, 'D') << endl;
    return 0;
}