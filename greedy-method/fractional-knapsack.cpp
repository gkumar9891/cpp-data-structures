#include <iostream>
using namespace std;

void display(int n, int arr[0][2]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
    }
}

void selectionSort(int n, int arr[][2]) {

    for(int i = 0; i < n - 1 ; i++) {
        double r1 = (double)arr[i][0] / (double)arr[i][1];

        for(int j = i; j < n; j++) {
            double r2 = arr[j][0] / arr[j][1];
 
             if(r2 < r1) {
 
                int temp[1][2];
                temp[0][0] = arr[i][0];
                temp[0][1] = arr[i][1];


                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];
                
                arr[j][0] = temp[0][0];
                arr[j][1] = temp[0][1];
            }
        }
    }
}


int fractionalKnapsack(int weight, int arr[][2], int n) {
    selectionSort(n, arr);

    double ans = 0.0;
    for(int i = n-1; i >= 0 ; i--) {
        if(weight >= arr[i][1]) {
            weight = weight - arr[i][1];
            ans = ans + (double)arr[i][0];
        } else {
            double temp = (double)weight / (double)arr[i][1];
            ans = ans + (temp * (double)arr[i][0]);
            break;
        }   
    }

    return ans;
}

int main() {

    int n = 3;
    int arr[][2] = { {100, 20}, {60, 10 }, {120, 30} };
    int w = 50;

    cout << fractionalKnapsack(w, arr, n);

    return 0;
}