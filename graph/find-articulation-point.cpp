#include <iostream>
#include <unordered_map>
#include <vector>
#define V 5

using namespace std;

void DFS(unordered_map <int, vector<int>> &adj, int u, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<int> &articulationPoints) {
    static int time = 0;
    disc[u] = low[u] = time;
    time++;

    for(int v: adj[u]) {
        if(disc[v] == -1) {
            parent[v] = u;
            DFS(adj, v, disc, low, parent, articulationPoints);

            low[u] = min(low[u], low[v]);

            if(low[v] >= disc[u] && parent[u] != -1) {
                articulationPoints.push_back(u);
            }
        } else if(v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }

    }
}

void findArticulation( unordered_map <int, vector<int>> &adj ) {
    
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);
    vector<int> articulationPoints;
    
    for(int i = 0; i < V; i++) {
        if(disc[i] == -1) {
            DFS(adj, i, disc, low, parent, articulationPoints);
        }

        if(parent[i] == -1 && adj[i].size() > 1) {
            articulationPoints.push_back(i);
        }
    }

    if(!articulationPoints.size()) {
        cout << "not any articulation point found" << endl;
        return;
    }

    for(auto it: articulationPoints) {
        cout << it << " ";
    }

}

int main() {

    unordered_map <int, vector<int>> adj;

    adj[0].push_back(3);
    adj[3].push_back(0);
    adj[3].push_back(4);
    adj[4].push_back(3);
    adj[0].push_back(4);
    adj[4].push_back(0);
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);


    findArticulation(adj);    

    return 0;
}
