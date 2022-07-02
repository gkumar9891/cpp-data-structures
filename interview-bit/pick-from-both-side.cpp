//https://www.interviewbit.com/problems/pick-from-both-sides/

#include <bits/stdc++.h>
using namespace std;

int solveProblem(vector <int> &A, int B) {
    // int temp = b;
    // vector <int> sumArray;
    // while(temp--) {
    //     int length = b - (temp + 1);
    //     int sum = 0;
    //     for(int i = 0; i <= temp; i++) {
    //         sum = sum + arr[i];
    //     }

    //     for(int i = arr.size() - length; i < arr.size(); i++) {
    //         sum = sum + arr[i];
    //     }

    //     sumArray.push_back(sum);
    // }


    // for(int i = b; i >= 0; i--) {
    //     sum = sum + sum;
    // }





    // int sum = 0;
    // for(int i = arr.size() - b; i < arr.size(); i++) {
    //     sum = sum + arr[i];
    // }

    // sumArray.push_back(sum);

    // int max = sumArray[0];
    // for(int i = 1; i < sumArray.size(); i++) {
    //     if(sumArray[i] > max){
    //         max = sumArray[i];
    //     }
    // }

    // return max;


  // int n = A.size();
  // int suff[n + 1];
  // suff[n] = 0;
  // suff[n - 1] = A[n - 1];
  // for (int i = n - 2; i >= 0; i--)
  //   suff[i] = A[i] + suff[i + 1];

  // int prefSum = 0;
  // int ans = suff[n - B];
  // for (int i = 0; i < B; i++) {
  //   prefSum = prefSum + A[i];
  //   int suffSum = suff[n - B + (i + 1)];
  //   ans = max(ans, prefSum + suffSum);
  // }
  // return ans;

  int n = A.size();
  int maxSum = 0;
  for(int i = 0; i < B; i++) {
    maxSum = maxSum + A[i];
  }

  int currentSum = maxSum, exclude = B - 1, include = n - 1;

  while(exclude >= 0 && include >= 0) {
      currentSum = currentSum + A[include] - A[exclude];
      exclude--; include--;
      maxSum = max(maxSum, currentSum);
  }

  return maxSum;
}

int main() {
    vector <int> arr = { 5, -2, 3, 1, 2 };
    cout << solveProblem(arr, 3);

    return 0;
}