#include <iostream>
using namespace std;

int l = 0;
int r = 0;

int cadaneAlgo(int arr[], int n) {
    int sum = 0, maxi = arr[0];

    for(int i = 0; i < n; i++) {
        sum += arr[i];

        // maxi = max(maxi, sum);
        //equivalent to above commented code done that so that we can also get the range         
        if(sum > maxi) {
            maxi = sum;
            r = i;
        }

        // sum = sum < 0 ? 0 : sum;

        // done arr[i] so that alog can used for -ve values also
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