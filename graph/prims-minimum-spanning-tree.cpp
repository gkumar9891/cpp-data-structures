#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    public:

    int vertex = 5;
    int edges = 6;
    map<int, list< pair<int, int> > > adj;

    void insert() {
        list<pair<int, int>> n0;
        n0.push_back( make_pair(1, 2) );
        n0.push_back(make_pair(3, 6));
        adj[0] = n0;

        list<pair<int, int>> n1;
        n1.push_back( make_pair(4, 5));
        n1.push_back(make_pair(3, 8));
        n1.push_back(make_pair(2, 3));
        n1.push_back(make_pair(0, 2));
        adj[1] = n1;
    
        list<pair<int, int>> n2;
        n2.push_back( make_pair(1, 3));
        n2.push_back(make_pair(4, 7));
        adj[2] = n2;

        list<pair<int, int>> n3;
        n3.push_back( make_pair(0, 6));
        n3.push_back(make_pair(1, 8));
        adj[3] = n3;

        list<pair<int, int>> n4;
        n4.push_back( make_pair(1, 5));
        n4.push_back(make_pair(2, 7));
        adj[4] = n4;
    
    }

    void DFS() {

    }

    int getMin(vector<int> &key, vector<bool> &mst) {
        int min = INT_MAX;
        int index = 0;

        for(int i = 0; i < key.size(); i++) {
            if(key[i] < min && mst[i] == false) {
                min = key[i];
                index = i;
            }
        }

        return index;
    }


    int display(vector<int> &parent) {
        int cost = 0;
        
        for(int i = 0; i < parent.size(); i++) {
            cout << parent[i] << " ";

            if(parent[i] == -1) {
                continue;
            } else {

                list< pair<int, int> >::iterator it;
                for(it = adj[i].begin(); it != adj[i].end(); it++ ) {

                    if(it->first == parent[i]) {
                        cost = cost + it->second;
                        break;
                    }
                }
            }
        }

        cout << endl;
        return cost;
    }


    void MST() {

        vector<int> key(vertex);
        vector<int> parent(vertex);
        vector<bool> mst(vertex);

        for(int i = 0; i < vertex; i++) {
            key[i] = INT_MAX;
            mst[i] = false;
            parent[i] = -1;
        }

        key[0] = 0;
        parent[0] = -1;

        for(int i = 0; i < vertex; i++) { 
            int u = getMin(key, mst);
            mst[u] = true;

            list< pair<int, int> >::iterator it;
            for(it = adj[u].begin(); it != adj[u].end(); it++ ) {
                int node = it->first;
                int weight = it->second;

                if(mst[node] == false && key[node] > weight) {
                    key[node] = weight;
                    parent[node] = u;
                }
            }
        }


        cout << display(parent);

    }
};

int main() {

    Graph *g = new Graph();
    g->insert();
    g->MST();


    return 0;
}