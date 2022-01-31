// #include <stdio.h>
// int main()
// {
//     char a[] = { 'A', 'B', 'C', 'D' };
//     char* ppp = &a[0];
//     printf("%d %c", ppp, *ppp++); // Line 1
//     printf("%d %c", ppp, *--ppp);
//     printf("%d %c", ppp, *ppp);
//     printf("%d %c", ppp, ++(*ppp));
//     printf("%d %c \n", ppp, ++(*ppp));
//     printf("%c %c ", *++ppp, ++(*ppp)); // Line 2

//     for(int i =0 ; i < 4; i++) {
//         printf("\n");
//         printf("%c", a[i]);
//     }
// }

// #include <stdio.h>
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5};
//     int *p = arr;
//     ++*p;
//     p += 2;
//     printf("%d \n", *p);
//     printf("%d", arr[1]);
//     return 0;
// }


#include <iostream>
using namespace std;

int fun();

int fun() {
    int b[2] = {1,2};
    return b;
}
int main() {

    int b[2] = fun();

    cout << b[0]; 
 
    return 0;
}


