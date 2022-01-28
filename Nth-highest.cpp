#include <iostream>
using namespace std;

int main() {

    int marks[] = {10, 20, 30, 40 ,50};
    int length = sizeof(marks) / sizeof(int);

    // to get 3rd highest number;

    int count;
    int input = 3;

    for(int i = 0; i < length; i++) {
       count = 0;

       for(int j = 0; j < length; j++) {
           if(marks[i] < marks[j]) {
               count++;
           }
       }

       if(input - 1 == count) {
           cout << marks[i] << " is 3rd highest";       
           break;
       }
    
    }

    

    return 0;
}