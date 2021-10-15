// https://www.codechef.com/problems/SEQUAT2

#include <iostream>
using namespace std;
int main() {
    int t, a, b, c, n, x, y;

    cin >> t;

    for(int i = 0; i < t; i++) {
        cin>>a;
        cin>>b;
        cin>>c;
        cin>>n;

        x = n;

        for(int j = 1; ;j++) {
            y = j;
            if( (x * y) == ((x | y) * (x & y) + a * x + b * y + c)) {
                break;
            }
        }
    }

    cout << x + y << " " << y + x ;

    return 0;
}