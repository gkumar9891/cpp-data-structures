#include <iostream>
using namespace std;

void main() {

    int t;
    int a;
    int b;

    cin >> t ;


    for(int i = 0; i < t; i++ ) {
        cin >> a;
        cin >> b;
    
        if(a < b) {
            cout << "<" << endl; 
        } else if( a > b) {
            cout << ">" << endl;
        } else if(a == b) {
            cout << "=" << endl;
        }
    }
}