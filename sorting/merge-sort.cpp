#include <iostream>
using namespace std;


void display(int n, int arr[]) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void merge(int l, int mid, int r, int arr[]) {
    int length1 = mid - l + 1;
    int length2 = r - mid;

    int a[length1];
    int b[length2];

    for(int i = 0; i < length1; i++) {
        a[i] = arr[l + i]; 
    }

    for(int j = 0; j < length2; j++ ) {
        b[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < length1 && j < length2){
        if(a[i] < b[j]) {
            arr[k] = a[i];
            k++; i++;
        } else {
            arr[k] = b[j];
            k++; j++;
        }
    }

    while(i < length1) {
        arr[k] = a[i];
        i++; k++;
    }

    while(j < length2) {
        arr[k] = b[j];
        j++; k++;
    }
}


void mergeSort(int l, int r, int arr[]) {
    if(l < r) {
        int mid = (l + r) / 2;

        mergeSort(l, mid, arr);
        mergeSort(mid + 1, r, arr);

        merge(l, mid, r, arr);
     }
}

int main() {
    int arr[8] = {6, 3, 9, 5, 2, 8, 7, 1};
    mergeSort(0, 7, arr);
    display(8, arr);

    return 0;
}