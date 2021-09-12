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
    int 8;
    // cin>>a;
    int arr[] = {{6676} 3216 4063 8373 423 586 8850 6762}}
    int *arr = new int[a];
    
    // for(int i = 0; i < a; i++) {
    //     cin >> *(arr + i);
    // }

    reversal(arr, a);

    for(int i = 0; i < a; i++) {
        cout << *(arr + i);
    }
}


