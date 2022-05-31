#include <iostream>
using namespace std;

class trieNode {
    public:
    char data;
    bool terminalNode = false;
    trieNode *children[26];

   
 
    trieNode(char val) {
        data = val;
    
         for(int i = 0; i < 26; i++) {
        children[i] = NULL;
    }

    }
};

class trie {
    public:
    trieNode *starting = new trieNode('*');
    
    void insert(trieNode* root, string word) {
        if(word.length() == 0) {
            root->terminalNode = true;
            return;
        }
        
        int index = word[0] - 'A';
        trieNode* temp;
        if(root->children[index] != NULL) {
            temp = root->children[index]; 
        } else {
            temp = new trieNode(word[0]);
            root->children[index] = temp;
        }

        insert(temp, word.substr(1));
    }

    void search(trieNode* root, string word) {
        if(word.length() == 0) {
           
           if(root->terminalNode == true) {
                cout << "key found";
           } else {
               cout << "key not found";
           }

            return ;
        }

        int index  = word[0] - 'A';
        if(root->children[index] != NULL && root->children[index]->data == word[0]) {
            search(root->children[index], word.substr(1));
        } else {
            cout << "key not found";
            return;
        }
    }

    void deleteWord(trieNode* root, string word) {
        if(word.length() == 0) {
            if( root->terminalNode = true) {
                root->terminalNode = false;
            } else {
                cout << "cannot delete becuase cannto exist";
            }

            return ;
        }

        int index  = word[0] - 'A';
        if(root->children[index] != NULL && root->children[index]->data == word[0]) {
            deleteWord(root->children[index], word.substr(1));
        } else {
            cout << "cannot delete becuase cannto exist";
    
            return ;
        }
    }
};

int main() {

    trie *t = new trie();
    t->insert(t->starting, "GAURAV");
    t->insert(t->starting, "RAVI");
    t->insert(t->starting, "SUBHAM");
    t->insert(t->starting, "RAV");
    t->search(t->starting, "RAV");
    t->deleteWord(t->starting, "RAV");
    t->search(t->starting, "RAV");
    return 0;
}