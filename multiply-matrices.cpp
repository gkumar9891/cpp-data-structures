#include <iostream>
using namespace std;
void matrixFiller(int*, char, int);
void multiplier(int*, int*, int*, int);
void matrixTraverser(int*, int);
int main() {

    int a[3][3];
    int b[3][3];
    int c[3][3];

    matrixFiller((int*)a, 'A', 3);
    matrixFiller((int*)b, 'B', 3);
    multiplier((int*)a, (int*)b, (int*)c, 3);

    cout << "multiple of matrices" << endl;
    matrixTraverser((int*)c, 3);

    return 0;
}

void matrixFiller(int* matrix, char name, int size) {   
    cout << "Enter the values for matrix " << name << endl;

    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            cin >>  *((matrix+i*size) + j);

}

void multiplier(int* matrix1, int *matrix2, int *matrix3, int size) {
    int sum = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            sum = 0;

            for(int k = 0; k < 3; k++) {
                sum = sum + *((matrix1+i*size) + k) * *((matrix2+k*size) + j);
            }
            
            *((matrix3+i*size) + j) = sum;
        }
    }
};

void matrixTraverser(int* matrix, int size) {
    for(int i=0; i < size; i++) {
        cout << endl;

       for(int j =0; j < size; j++)
         cout <<*((matrix+i*size) + j) << "\t";
    
    }
}