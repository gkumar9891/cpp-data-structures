#include <iostream>
#include <vector>

using namespace std;

void merge(int l, int mid, int h, vector<int> &arr, int &invertibles){
    int length_a = mid - l + 1;
    int length_b = h - mid;
    
    vector<int> temp_a(length_a);
    vector<int> temp_b(length_b);

    for(int i = 0; i < length_a; i++) {
        temp_a[i] = arr[l + i];
    } 

    for(int i = 0; i < length_b; i++) {
        temp_b[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while(i < length_a && j < length_b) {
        if(temp_a[i] < temp_b[j]) {
            arr[k] = temp_a[i];
            k++; i++;
        } else {
            

             invertibles = invertibles + length_a - i;
            arr[k] = temp_b[j];
            k++; j++;
        }
    }

    while(i < length_a) {
        arr[k] = temp_a[i];
        k++; i++;
    }

    while(j < length_b) {
        arr[k] = temp_b[j];
        k++; j++;
    }
}

void mergeSort(int l, int h, vector<int> &arr, int &invertibles) {
    if(l < h) {
        int mid = (l + h) / 2;
        mergeSort(l, mid, arr, invertibles);
        mergeSort(mid+1, h, arr, invertibles);
        merge(l, mid, h, arr, invertibles);
    }
}


int calcInvertibles(vector<int> &arr) {
    int invertibles = 0;
    mergeSort(0, arr.size() - 1, arr, invertibles);
    return invertibles;
}

int main() {
    vector<int> arr(4);
    arr[0] = 7;
    arr[1] = 5;
    arr[2] = 3;
    arr[3] = 1;
    cout << calcInvertibles(arr);

    return 0;
}