#include <iostream>
#include <climits>
#define in INT_MAX 
#define V 4

using namespace std;

void floydWarshall(int graph[V][V]) {

	for(int k = 0; k < V; k++) { // try for all intermediate nodes
		for(int i = 0; i < V; i++) { // try for all starting point 
			for(int j = 0; j < V; j++) { // try for all ending point
				if(graph[i][k] == in || graph[k][j] == in) {
					continue;
				} else if(graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	for(int i = 0; i < V; i++) {
		if(graph[i][i] < 0) {
			cout << "negative cycle exist";
			break;
		}
	}

	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++) 
			cout<<i<<" to "<<j<<" distance is "<<graph[i][j]<<"\n";
			cout<<"=================================\n";
	}
}

int main() {

	int graph[V][V] = {
		{0, 3, in, 5},
		{2, 0, in, 8},
		{in, 1, 0, 2},
		{in, in, 2, 0}
	};

	floydWarshall(graph);

	return 0;
}
