#include <iostream>
using namespace std;

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
    //     int last = size - 1;
    //     arr[0] = arr[last];
    //     arr[last] = 0;
    //     size--;

         
        
    //     int i = 0;
    //     int left = 2 * i + 1;
    //     int right = 2 * i + 2;

    //     while(arr[i] < arr[left] || arr[i] < arr[right]) {
    //         if(arr[left] > arr[right]) {
    //             int temp = arr[i];
    //             arr[i] = arr[left];
    //             arr[left] = temp;
    //             i = left;
    //         } else {
    //             int temp = arr[i];
    //             arr[i] = arr[right];
    //             arr[right] = temp;
    //             i = right;
    //         }

    //         left = 2 * i + 1;
    //         right = 2 * i + 2;
    //     }


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

    heap h;
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(10);
    h.insert(2);
    h.insert(90);
    h.print();
    cout << endl;
    h.deleteNode();
 
    h.print();


    return 0;
}