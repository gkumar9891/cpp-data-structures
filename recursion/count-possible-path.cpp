#include <iostream>
using namespace std;
 
int calculatePath(int start, int end) {
    if(start == end) {
        return 1;
    }

    if(start > end) {
        return 0;
    }

    int count = 0;
    for(int i = 1; i <= 6; i++) {
        count = count + calculatePath(start + i, end);
    }

    return count;



}

int main() {

    cout << calculatePath(0, 3);

    return 0;
}