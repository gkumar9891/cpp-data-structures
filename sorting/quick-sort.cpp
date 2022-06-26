#include <iostream>
using namespace std;

int placeRight(int l, int h, int arr[]) {
    int pivot = arr[h];
    int i = l - 1;
    for(int j = l; j < h; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = pivot;
    arr[h] = temp;

    return i + 1;
}

void quickSort(int l, int r, int arr[]) {
    if(l < r) {
        int pivotIndex = placeRight(l, r, arr);
        quickSort(l, pivotIndex - 1, arr);
        quickSort(pivotIndex + 1, r, arr);
    }
}


void display(int n, int arr[]) {
     for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

int main() {

    int arr[] = {5, 3, 6, 2, 3, 1, 10};
    quickSort(0, 6, arr);
    display(7, arr);
    return 0;
}