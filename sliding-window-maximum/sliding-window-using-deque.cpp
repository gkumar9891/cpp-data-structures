#include <iostream>
#include <deque>
using namespace std;

void maxSlidingWindow(int arr[], int size, int k) {
  
  deque<pair<int, int>> container;
  
  for(int i = 0; i < size; i++) {
    if(!container.empty() && container.front().second <= (i - k)) {
        container.pop_front();
    }

    while(!container.empty() && container.back().first < arr[i]) {
        container.pop_back();
    }

    container.push_back(make_pair(arr[i], i));
    
    if(i >= (k - 1)) {
        cout << container.front().first << " ";
    }
  }
}

int main() {
    int size = 11;
    int arr[size] = {4, 1, 3, 5, 1, 2, 3, 2, 1, 1, 5};
    int k = 3;

    maxSlidingWindow(arr, size, k);



    return 0;
}
