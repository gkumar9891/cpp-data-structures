#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    } 

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n , largest);
    }
}

void buildHeap(int arr[], int n) {
    for(int i = n/2 - 1 ; i >= 0; i-- ){ 
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

class heap {
    public:
    int arr[100];
    int size = 0;

    void insert(int val) {
        arr[size] = val;
        size++;

        if(size == 1) {
            return;
        }

        int  current = size - 1;
        int parent = current/2;

        while(arr[current] > arr[parent]){
            int temp = arr[current];
            arr[current] = arr[parent];
            arr[parent] = temp;

            current = parent;
            parent = current / 2;
        }
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }

    void deleteNode() {

    arr[0] = arr[size - 1];
    size--;
    int n = size - 1; 
    int i = 0;

    while(i < n) {
        int left = arr[2 * i + 1];
        int right = arr[2 * i + 2];

        int larger = left > right ? 2*i+1 : 2*i+2;

        if(larger > size) {
            break;
        }

        if(arr[i] < arr[larger]) {
            int temp = arr[i];
            arr[i] = arr[larger];
            arr[larger] = temp;

            i = larger;
        } else {
            return ;
        }
    }
    }


};

int main() {

    // heap h;
    // h.insert(50);
    // h.insert(40);
    // h.insert(30);
    // h.insert(20);
    // h.insert(10);
    // h.insert(2);
    // h.insert(90);
    // h.print();
    // cout << endl;
    // h.deleteNode();
 
    // h.print();


    int arr[] = {10, 20, 15, 2, 10, 30, 60};

    buildHeap(arr, 7);

    heapSort(arr, 7);

    for(int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }



    return 0;
}