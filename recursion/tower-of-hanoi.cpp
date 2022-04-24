#include <iostream>
using namespace std;
void TOH(int disk, char source, char helper, char target ) {

    if( disk == 0) {
        return;
    }

    TOH(disk -1 ,source, target, helper);
    cout << source << " to " << target << endl;
    TOH(disk -1, helper, source, target );

}


int main() {
    TOH(4, 'S', 'H', 'T');
    return 0;
}