#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define V 5

void DFS( unordered_map<int, vector<int>> &adj, int u, vector <int> &disc, vector <int> &low, vector <int> &parent, vector < pair<int, int> > &bridge ) {
	static int time  = 0;
	disc[u] = low[u] = time;
	time++;

	for(int v: adj[u]) {
		if(disc[v] == -1) { //not visited
			parent[v] = u;
			DFS(adj, v, disc, low, parent, bridge);

			low[u] = min(low[u], low[v]);

			if(low[v] > disc[u]) {
				bridge.push_back( make_pair(u, v) );	
			}
		
		} else if ( v != parent[u] ) {
			low[u] = min(low[u], low[v]);
		}	
	}
}

void findBridge(unordered_map<int, vector<int>> &adj, vector <int> &disc, vector <int> &low, vector <int> &parent) {

	vector < pair<int, int> > bridge;

	for(int i = 0; i < V; i++) {
		if(disc[i] == -1) {
			DFS(adj, i, disc, low, parent, bridge);
		}
	}

	if( !bridge.size() ) {
		cout << "No Bridge Found";
		return;
	}

	cout << "bridges are" << endl;
	for(auto it: bridge) {
		cout<<it.first<<"-->"<<it.second<<"\n";
	}

	

}

int main() {

	unordered_map<int, vector<int>> adj;
	adj[0].push_back(1);
	adj[0].push_back(2);
	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(0);
	adj[0].push_back(3);
	adj[3].push_back(4);

	vector <int> disc(V, -1);
	vector <int> low(V, -1);
	vector <int> parent(V, -1);


	findBridge(adj, disc, low, parent);	

	return 0;
}