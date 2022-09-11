#include <iostream>
#include <vector>
#include <climits>
#define E 10
#define V 5

using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

void bellmanFord( vector<Edge> &edges ) {

    vector<int> parent(V);
    vector<int> cost(V, INT_MAX);
    vector<int> values(V, INT_MAX);

    parent[0] = -1;
    cost[0] = 0;
    values[0] = 0;

    bool isUpdated;

    for(int i = 0; i < V - 1; i++) {
        isUpdated = false;

        for(int j = 0; j < edges.size(); j++) {
            int source = edges[j].source;
            int destination = edges[j].destination;
            int weight = edges[j].weight; 

            if(cost[source] + weight < cost[destination]) {
                cost[destination] = cost[source] + weight;
                parent[destination] = source;
                values[destination] = cost[destination];
                isUpdated = true;
            }
        }

        if(isUpdated == false) {
            break;
        }
    }

    if(isUpdated) {
        for(int j = 0; j < edges.size(); j++) {
            int source = edges[j].source;
            int destination = edges[j].destination;
            int weight = edges[j].weight; 

            if(cost[source] + weight < cost[destination]) {
                cout << "-ve cycle exist" << endl;
                return;
            }
        }  
    }


    for(int i = 1; i < V; i++) {
        cout << "cost to reach from 0 to " << i << " is " << cost[i] << endl;
    }
}

int main() {
    vector<Edge> edges(E);

    edges[0].source = 0;
    edges[0].destination = 1;
    edges[0].weight = 6;

    edges[1].source = 0;
    edges[1].destination = 2;
    edges[1].weight = 7;

    edges[2].source = 1;
    edges[2].destination = 2;
    edges[2].weight = 8;

    edges[3].source = 1;
    edges[3].destination = 3;
    edges[3].weight = -4;

    edges[4].source = 1;
    edges[4].destination = 4;
    edges[4].weight = 5;

    edges[5].source = 2;
    edges[5].destination = 3;
    edges[5].weight = 9;

    edges[6].source = 2;
    edges[6].destination = 4;
    edges[6].weight = -3;

    edges[7].source = 3;
    edges[7].destination = 4;
    edges[7].weight = 7;

    edges[8].source = 3;
    edges[8].destination = 0;
    edges[8].weight = 2;

    edges[9].source = 4;
    edges[9].destination = 1;
    edges[9].weight = -2;

    bellmanFord(edges);

    return 0;
}