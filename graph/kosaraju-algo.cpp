#include <iostream>
#include <vector>
#include <stack>

#include <unordered_map>

#define V 8

using namespace std;


void DFS1(int u, vector<bool> &visited, unordered_map<int, vector<int> > &adj, stack<int> &stk) {
    if(visited[u]) {
        return;
    }

    visited[u] = true;

    for(auto v: adj[u]) {
        DFS1(v, visited, adj, stk);
    }

    stk.push(u);
}

void reverse(unordered_map<int, vector<int>> &adj, unordered_map<int, vector<int>> &rev){
    for(int u = 0; u < V; u++) {
        for(int v: adj[u]) {
            rev[v].push_back(u);
        }
    }
};

void resetVisited(vector<bool> &visited) {
    for(int i = 0; i < V; i++) {
        visited[i] = false;
    }
}

void DFS2(int u, vector<bool> &visited, unordered_map<int, vector<int>> &rev) {

    cout << u << " ";

    visited[u] = true;

    for(auto v: rev[u]) {
        if(!visited[v]) {
            DFS2(v, visited, rev);
        }
    }
};

void findSCC( unordered_map<int, vector<int>> &adj, vector<bool> &visited) {
    stack<int> stk;

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            DFS1(i, visited, adj, stk);
        }
    }

    unordered_map<int, vector<int>> rev;
    reverse(adj, rev);
    resetVisited(visited);

    
    while(!stk.empty()) {
        int current = stk.top();
        stk.pop();
        if(!visited[current]) {
          DFS2(current, visited, rev);
          cout << endl;
        }
    }

    // for(int i = 0; i < V; i++) {
    //     for(int v: rev[i]) {
    //         cout << i << " --- " << v << endl;
    //     }
    // }

    // while(!stk.empty()) {
    //     cout << stk.top();
    //     stk.pop();
    // }
}


int main() {

    unordered_map<int, vector<int> > adj;
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(4);
    adj[4].push_back(5);
    adj[5].push_back(6);
    adj[6].push_back(4);
    adj[4].push_back(7);
    adj[6].push_back(7);

    vector<bool> visited(V, false);
   

    findSCC(adj, visited);

    return 0;
}