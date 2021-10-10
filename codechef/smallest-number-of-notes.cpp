// counter-reset: item;
// contnet: counter(item);
//counter-increment: item;




#include <iostream>
using namespace std;

int main () {

    int collectionOfNotes[] = {100, 50, 10, 5, 2, 1};
    int t;
    int n;
    int totalNotes;

    cin >> t;
    
    for(int i = 0; i < t; i++) {
        totalNotes = 0;
        cin >> n;
        
        for(int j = 0; j < 6; j++ ) {
            if(n >= collectionOfNotes[j]) {
                totalNotes = totalNotes + ( n / collectionOfNotes[j] );
            
                if( n % collectionOfNotes[j] != 0) {
                    n = n % collectionOfNotes[j];
                 }else {
                     break;
                 }
            }
        }

        cout << totalNotes << endl;
    }

    return 0;
}