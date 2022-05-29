#include <iostream>
using namespace std;

class linkedList {
    public:
    int vertexNo;
    linkedList *next = NULL;
};

class Graph{
    public:
    int verteces;
    int edges;
    linkedList *adj;

    void buildGraph() {
        cout << "please enter total number of verteces you want" << endl;
        cin >> verteces;

        cout << "please enter total number of edges you want" << endl;
        cin >> edges;
        adj = new linkedList[verteces];


        for(int i = 0; i < verteces; i++) {
            adj[i].vertexNo = i;
            adj[i].next = &adj[i];
        } 

        for(int i = 0; i < edges; i++) {
            cout << "enter the first node and second node" << endl;
            int first,second;
            linkedList *t;
            cin >> first >> second;
            t = &adj[first];

            while(t->next != &adj[first]){
                t = t->next;
            }

            linkedList *temp = new linkedList();
            temp->vertexNo = second;
            t->next = temp;
            temp->next = &adj[first];
            
        }

        printGraph();
    }

    void printGraph() {
        cout << endl;
          for(int i = 0; i < verteces; i++) {
                linkedList *temp = &adj[i];
                while(temp->next != &adj[i]) {
                    cout << temp->vertexNo << " ";
                    temp = temp->next;
                }

            cout << temp->vertexNo << endl;

          }
    }
};


int main() {

    Graph *g = new Graph();
    g->buildGraph();

    return 0;
}
