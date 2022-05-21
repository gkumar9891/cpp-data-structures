#include <iostream>
using namespace std;

int search(int[], int, int, bool);

void findFirstAndLastPosition(int arr[], int size, int target) {

    int ans[] = {-1, -1};

    bool findFirst;

    ans[0] = search(arr, size, target, findFirst = true);
    ans[1] = search(arr, size, target, findFirst = false);

    cout << ans[0] << " ";
    cout << ans[1];
}


int search(int arr[], int size, int target, bool findFirst) {

    int ans = -1;
    int start = 0;
    int end = size - 1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if(arr[mid] > target) {
            end = mid - 1;
        } else if(arr[mid] < target) {
            start = mid + 1;
        } else {
            ans = mid;
            if(findFirst) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    return ans;
}

 
int main() {

    int arr[] = {5, 7, 7, 8, 8, 10};

    findFirstAndLastPosition(arr, 6, 7);

    return 0;
}