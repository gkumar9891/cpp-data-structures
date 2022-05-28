#include <iostream>
using namespace std;

class Graph{
    public:
    int verteces;
    int edges;
    int **adj;

    void createGraph() {
        cout << "enter total number of verteces you want" << endl;
        cin >> verteces;

        cout << "enter total number of edges you want" << endl;
        cin >> edges;
    
        adj = new int*[verteces];
        for(int i = 0; i < verteces; i++) {
            for(int j = 0; j < verteces; j++) {
                adj[i] = new int[verteces];
            }
        }
  
        for(int i = 0; i < verteces; i++) {
            for(int j = 0; j < verteces; j++) {
                adj[i][j] = 0;
            }
        }

        for(int i = 0; i < edges; i++) {
            cout << "enter the adj" << endl;
            int start, end;
            cin >> start;
            cin >> end;

            adj[start][end] = 1;
            adj[end][start] = 1;
        }


        cout << "graph created" << endl;    
        for(int i = 0; i < verteces; i++) {
            for(int j = 0; j < verteces; j++) {
                cout << adj[i][j];
            }
            cout << endl;
        }
    }
};

int main() {

    Graph *G = new Graph();
    G->createGraph();
    return 0;
}
