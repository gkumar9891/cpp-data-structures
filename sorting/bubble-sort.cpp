#include <iostream>
using namespace std;

void display(int n, int arr[]) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int n, int arr[]) {
    for(int i = n; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {

    int arr[] = {12, 45, 23, 51, 19, 8};
    bubbleSort(6, arr);
    display(6, arr);


    return 0;
}