#include <iostream>
using namespace std;

void display(int n, int arr[]) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void insertionSort(int n, int arr[]) {
    for(int i = 1; i < n; i++) {
        int temp = arr[i];
        for(int j = i - 1; j >= 0; j--) {
            if(temp < arr[j]) { 
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    } 
}

int main() {

     int arr[] = {34, 1234, 23, 23, 34 , 20};
    insertionSort(6, arr);
    display(6, arr);

    return 0;
}