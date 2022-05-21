#include <iostream>
using namespace std;

int findCeiling(int arr[], int size, int target) {

    int start = 0;
    int end = size - 1; 
    

    while(start <= end) {

        int mid = (start + end) / 2;

        if(arr[mid] == target) {
            start = mid;
            break;
        }

        if(arr[mid] > target) {
            end = mid - 1;
      
        } else {
            start = mid + 1;
      
        }
    }
    return arr[start];
}


int main() {

    // target = 5;
    // ceiling will be 7
    int arr[] = {2,3,5,9,14,16,18};
    int ans = findCeiling(arr, 7, 18);
    cout << ans;


    return 0;
}