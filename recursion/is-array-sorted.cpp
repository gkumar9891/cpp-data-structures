#include <iostream>
using namespace std;

bool sorted(int arr[], int n) {
    if(n == 1) {
    return true;
    }
    
    bool sortedArray = sorted(arr + 1, n - 1);
    cout << arr[0] << " " << arr[1] << " " << n <<  endl ; 
    return (arr[0] < arr[1] && sortedArray);
}

int main() {

    int a[] = {1,2,3,4,5};

    cout << sorted(a, 5);

    return 0;
}