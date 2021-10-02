// hackerrank problem https://www.hackerrank.com/challenges/2d-array/problem

#include<iostream>
using namespace std;
#define length 3

int main() {
  int arr[length][length];
  arr[0][0] = -9;
  arr[0][1] = -9;
  arr[0][2] = -9;
  arr[1][0] = 0;
  arr[1][1] = -9;
  arr[1][2] = 0;
  arr[2][0] = -9;
  arr[2][1] = -9;
  arr[2][2] = -9;

  int sum = 0;


  for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++ ) {
          sum = sum + arr[i][j];

          if( (i == 1 && j == 0) || (i == 1 && j == 2)) {
              continue;
          }
      }
  }

  cout << sum;

  return 0;

}