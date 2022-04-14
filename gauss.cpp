#include <iostream>
#include <stdlib.h>

using namespace std;


void augumentedArray(int *a, int *b, int *c) {

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 4 ; j++) {
                if(j == 3) {
                    *((c + i * 4) + j) =  *((b + i) + 0);
                    continue;
                }

                *((c + i * 4) + j) = *((a + i * 3) + j);
            }
        }
}


void matrixTraverser(int* matrix, int size) {
    for(int i=0; i < 3; i++) {
        cout << endl;

       for(int j =0; j < 4; j++)
         cout <<*((matrix+i*4) + j) << "\t";
    
    }
}

int main() {

    system("cls");

    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int b[3][1] = {14,15,16};

    int c[3][4];

    // int *d = &a[0][0];
    // cout << *((d + 2 * 4)+ 3);
    augumentedArray(&a[0][0], &b[0][0], &c[0][0]);

    matrixTraverser(&c[0][0], 3);

    // delete(a);
    // delete(b);
    // delete(c);

    return 0;
}

