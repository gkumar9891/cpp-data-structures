#include <iostream>
using namespace std;

int l = 0;
int r = 0;

int cadaneAlgo(int arr[], int n) {
    int sum = 0, maxi = arr[0];

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // maxi = max(maxi, sum);
        if(sum > maxi) {
            maxi = sum;
            r = i;
        }

        if(sum < arr[i]) {
            sum = arr[i];
            l = i;
        }
    }

    return maxi;
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    cout << cadaneAlgo(arr, n) << " " << l <<" "<< r << " " << endl;

    return 0;
}