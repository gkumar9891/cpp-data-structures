#include <iostream>
using namespace std;


void matrixFiller(int*, char, int);
void matrixTraverser(int*, int);
int (*(matrixAdder)(int*, int*, int))[3];

void matrixFiller(int* matrix, char name, int size) {   
    cout << "Enter the values for matrix " << name << endl;

    for(int i=0; i < size; i++)
        for(int j=0; j < size; j++)
            cin >>  *((matrix+i*size) + j);

}

void matrixTraverser(int* matrix, int size) {
    for(int i=0; i < size; i++) {
        cout << endl;

       for(int j =0; j < size; j++)
         cout <<*((matrix+i*size) + j) << "\t";
    
    }
}
int (*(matrixAdder)(int* matrix1, int* matrix2, int size))[3] {

    static int matrix3[3][3];

    for(int i=0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            matrix3[i][j] = *((matrix1+i*3) + j) + *((matrix2+i*3) + j);


    cout << "sum of matrix is" << endl;
    // matrixTraverser((int*)matrix3, 3);



    return matrix3;

}

int main() {

    int a[3][3];
    int b[3][3];

    matrixFiller((int*)a, 'A', 3);
    matrixFiller((int*)b, 'B', 3);

    int (*c)[3] = matrixAdder((int*)a, (int*)b, 3);

     matrixTraverser((int*)c, 3);

    return 0;
}