#include <iostream>
using namespace std;

int constructSegmentTree(int arr[], int segmentTreeArray[], int segmentTreeIndex, int l, int r){
    if(l == r) {
        segmentTreeArray[segmentTreeIndex] = arr[l];
        return arr[l];
    }
    
    int mid = (l + r) / 2;

    segmentTreeArray[segmentTreeIndex] = constructSegmentTree(arr, segmentTreeArray, 2 * segmentTreeIndex + 1, l, mid) + constructSegmentTree(arr, segmentTreeArray, 2 * segmentTreeIndex + 2, mid + 1, r);

    return segmentTreeArray[segmentTreeIndex];
}

int findSum(int segmentTreeArray[], int si, int sl, int sr, int l, int r) {

    if(sl >= l && sr <= r) {
        return segmentTreeArray[si];
    }

    if(sr < l || sl > r) {
        return 0;
    }

    int mid = (sl + sr) / 2;

    return findSum(segmentTreeArray, 2 * si + 1, sl, mid, l, r) + 
    findSum(segmentTreeArray, 2 * si + 2, mid + 1, sr, l, r);
}

void updateSegmentTree(int segmentTreeArray[], int si, int sl, int sr, int index, int diff) {
    if(sl > index || sr < index) {
        return;
    }
    
    segmentTreeArray[si] += diff;
    if(sl != sr) {
        int mid = (sl + sr) / 2;
        updateSegmentTree(segmentTreeArray, 2 * si + 1, sl, mid, index, diff);
        updateSegmentTree(segmentTreeArray, 2 * si + 2, mid + 1, sr, index, diff);
    }
}

int main() {

    int arr[6] = {1, 2, 5, 6, 7, 9};
    int segmentTreeArray[16];

    constructSegmentTree(arr, segmentTreeArray, 0, 0, sizeof(arr) / sizeof(arr[0]) - 1);

    cout << findSum(segmentTreeArray, 0, 0, 5, 2, 4);

    //used to update an index a find the sum again easily;
  
    int index = 3;
    int diff = 14 - arr[index];
    arr[index] = 14;
    updateSegmentTree(segmentTreeArray, 0, 0, 5, index, diff);
    cout << " ";
    cout << findSum(segmentTreeArray, 0, 0, 5, 2, 4);

    // for(int i = 0; i < 16; i++) {
    //     cout << segmentTreeArray[i] << endl;
    // }

    return 0;
}