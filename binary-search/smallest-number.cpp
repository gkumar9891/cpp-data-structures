#include <iostream>
using namespace std;

char greatercharacter(char arr[], int size, char target) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {    
        int mid = (start + end) / 2;
        
        if(arr[mid] > target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return arr[start % size];
}


int main() {

    char arr[] = {'a', 'b', 'c', 'e'};

    char ch = greatercharacter(arr, 4, 'b' );

    cout << ch;


    return 0;
}