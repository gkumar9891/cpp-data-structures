#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[], int src, int dest) {
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

bool BFS(vector<int> adj[], int src, int dest, int v, int dist[], int pred[]) {
    
    bool visited[v];
    list<int> queue;

    for(int i = 0; i < v; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;   
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    queue.push_back(src);

    while(!queue.empty()) {
        int u = queue.front();
        queue.pop_front();

        for(int i = 0; i < adj[u].size(); i++) {
            if(visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                queue.push_back(adj[u][i]);

                if(adj[u][i] == dest) {
                    return true;
                }
            }
        }
    }

    return false;
}


void findShortestDistance(vector<int> adj[], int src, int dest, int v, int dist[], int pred[]) {
    if( BFS(adj, src, dest, v, dist, pred) == false ) {
        cout << "path is not possible" << endl;
    
        return;

    }


    cout << "shorted length is " << dist[dest] << endl;

    vector<int> path;
    int crowl = dest;
    path.push_back(crowl);

    while(pred[crowl] != -1) {
        path.push_back(pred[crowl]);
        crowl = pred[crowl];
    }

    for(int i = path.size()-1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}

int main() {

    int v = 8;
    vector<int> adj[v];
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);

    int src = 0;
    int dest = 7;
    int dist[v];
    int pred[v];

    findShortestDistance(adj, src, dest, v, dist, pred);

    return 0;
}
