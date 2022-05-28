#include <iostream>
#include <map>
using namespace std;

class hashTable {
    public:
    map<int, int> m;
    int length = 0;

    int hashFunction(int key){
        return key % 10;
    }

    void add(int key, int value) {
        int index = hashFunction(key);
        m[index] = value;
    }

    void search(int key) {
        int index = hashFunction(key);
        cout << m[index];
    }
};
int main() {

     int times;
     cout << "How many times you want to add. " << endl;
     cin >> times;

     hashTable ht;

     for(int i = 0; i < times; i++) {
         int key;
         int value;
         cout << "add one time key value respectively" << endl;
         cin >> key >> value;
         ht.add(key, value);
     }

    
     cout << "which key you want to search" << endl;
     int j;
     cin >> j; 
     ht.search(j);

    
     for(auto i = ht.m.begin(); i != ht.m.end(); i++) {
         cout << endl << i->first << " " << i->second;
     }

 
     return 0;
}