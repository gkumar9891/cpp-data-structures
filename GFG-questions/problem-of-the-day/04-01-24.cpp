#include <bits/stdc++.h>
using namespace std;

int singleElement(int arr[], int N) {
    int ones = 0;
    int twos = 0;
    int common_bit_mask;

    for (int i = 0; i < N; i++) {
        // Update twos using OR operation
        twos = twos | (ones & arr[i]);

        // Update ones using XOR operation
        ones = ones ^ arr[i];

        // Update common_bit_mask
        common_bit_mask = ~(ones & twos);

        // Remove common bits from ones and twos
        ones = ones & common_bit_mask;
        twos = twos & common_bit_mask;
    }

    return ones;
}

int main() {

    int arr[] = {1, 10, 1, 1};
    int n = 4;
    cout << singleElement(arr, n);
    return 0;
}