#include <iostream>
using namespace std;

int firstocc(int arr[], int size, int i, int key){
    if(arr[i] == key) {
        return i;
    }

    if(i == size) {
        return -1;
    }

     return firstocc(arr, size, i + 1, key);
}

int lastocc(int arr[], int size, int i, int key) {
    if( i == size) {
        return -1;
    }
    int restArray = lastocc(arr, size, i + 1, key);
    if(restArray != -1) {
        return restArray;
    };

    if(arr[i] == key) {
        return i;
    }

    return -1;
}

int main() {

    int arr[] = {4,2,1,2,5,2};
    cout << firstocc(arr, 6, 0, 10) << endl;
    cout << lastocc(arr, 6, 0, 5);

    return 0;
}