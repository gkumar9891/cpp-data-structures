#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void findSolution(vector<int> &solution, int arr[], int size, int k) {
    priority_queue<pair<int, int>> heap;

    for(int i = 0; i < size; i++) {
        while(!heap.empty() && heap.top().second <= (i-k)) {
            heap.pop();
        }

        heap.push(make_pair(arr[i], i));

        if(i>=k-1) {
            cout << heap.top().first << " ";
        }
 
    }

}

int main() {
    //solution is [4, 5, 5, 5, 3, 3, 3, 2, 5];

    int size = 11;
    int arr[size] = {4, 1, 3, 5, 1, 2, 3, 2, 1, 1, 5};
    int k = 3;
    vector<int> solution;


    findSolution(solution, arr, size, k);




    return 0;
}