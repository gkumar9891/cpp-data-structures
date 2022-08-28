#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

void dijkstra(vector<int> &dist, set< pair<int, int> > &distSet, int source, vector< vector< pair<int, int> > > &graph) {

    while( !distSet.empty() ) {
        auto top = distSet.begin();
        int node = top->first;

        distSet.erase( distSet.begin() );

        for(int i = 0; i < graph[node].size(); i++) {

            int distance = dist[node];

            //pair structure [node, dist]
            int adjNode = graph[node][i].first;
            int adjDist = graph[node][i].second;

            distance = distance + adjDist;
            
            if( dist[adjNode] > distance ) {
                dist[adjNode] = distance;
                distSet.insert( make_pair(adjNode, adjDist) );
            }        
           
        }        
    }


    for(int i = 0; i < dist.size(); i++) {
        cout << dist[i] << " ";
    }
}


int main() {

    int vertex = 5; 

    vector< vector< pair<int, int> > > graph = {
       {  {1,7}, {2,1}, {3, 2} },
       { {0,7}, {2,3}, {3, 5}, {4, 1} },
       { {0, 1}, {1, 3} },
       { {0, 2}, {1, 5}, {4, 7} },
       { {1, 1}, {3, 7} }
    };

    vector<int> dist( vertex );
    set< pair<int, int> >distSet;

    for(int i = 0; i < vertex; i++) {
        dist[i] = INT_MAX;
    }

    int source = 0;
    dist[source] = 0;
    distSet.insert( make_pair(0, 0) );

    dijkstra(dist, distSet, source, graph);


    // set< pair<int, int> >::iterator distSetIt;

    // for( distSetIt = distSet.begin(); distSetIt != distSet.end(); distSetIt++) {
    //     cout << distSetIt->first;
    // }


    // for(int i = 0; i < graph.size(); i++) {
    //     for(int j = 0; j < graph[i].size(); j++) {
    //         cout << graph[i][j].first << " ";
    //     }
    // }

    return 0;
}