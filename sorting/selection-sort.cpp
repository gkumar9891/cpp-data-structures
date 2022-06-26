#include <iostream>
using namespace std;

// void selectionSort(int n, int arr[]){
//     for(int i = 0; i < n; i++) {
//        int smallestIndex = i;
//         for(int j = i; j < n; j++) {
//                 if(arr[j] < arr[smallestIndex] ) {
//                     smallestIndex = j;
//                 }
//         }

//         int temp = arr[i];
//         arr[i] = arr[smallestIndex];
//         arr[smallestIndex] = temp;
//     }
// };

//above version is also correct just taking little more steps

void selectionSort(int n, int arr[]){
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[i]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
 }

void display(int n, int arr[]) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[] = {12, 45, 23, 51, 19, 8};
    selectionSort(6, arr);
    display(6, arr);


    return 0;
}