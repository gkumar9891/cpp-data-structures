// question form hackerrank data-structures Arrays - DS


#include <bits/stdc++.h>
using namespace std;

void reversal(int* arr, int h){
    int l = 0;
    h = h - 1;
    int temp;

    while(l < h) {
        temp = *(arr + l);
        *(arr + l) = *(arr + h);
        *(arr + h) = temp;
    
        l++;
        h--;
    }
}

int main() {
    //** memory in stack
    int a = 8;
    int arry[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int* arr =  &arry[0];


    //memory in heap

    // int a;
    // cin>>a;
    // int *arr = new int[a];
    
    // for(int i = 0; i < a; i++) {
    //     cin >> *(arr + i);
    // }


    reversal(arr, a);

    for(int i = 0; i < a; i++) {
        cout << *(arr + i);
    }
}


