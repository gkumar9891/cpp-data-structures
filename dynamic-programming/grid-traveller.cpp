#include <iostream>
#include <map>
using namespace std;
 
int gridTraveller(int m, int n, map<int, int> &memo) {
    int key = m + n;

    if( memo.count(key) != 0) {
        return memo[key];
    }

    if(m == 0 || n == 0) {
        return 0;
    }

    if(m == 1 || n == 1) {
        return 1;
    }

    memo[key] = gridTraveller(m-1, n, memo) + gridTraveller(m, n -1, memo);
    return memo[key];
}

int main() {
    
    map<int, int> memo;
    cout << 
    gridTraveller(2, 3, memo);

    return 0;
}
