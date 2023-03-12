// https://www.hackerrank.com/challenges/find-the-nearest-clone/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
 
int BFS(int srcNode, vector<long> &ids, vector<int> adj[], int val) {
  int minMST = INT_MAX;
  queue<int> q;
  vector<int> values(ids.size() + 1, 0);
  vector<int> visited(ids.size() + 1, 0);
  q.push(srcNode);
  visited[srcNode] = 1;
  
  while(!q.empty()) {
      int node = q.front();
      q.pop();
      
      if(node != srcNode && ids[node-1] == val) {
           minMST = values[node] < minMST ? values[node] : minMST;
      }
      
      for(int i = 0; i < adj[node].size(); i++) {
        int v = adj[node][i];
        if(!visited[v]) {
            q.push(v);
            visited[v] = 1;
            values[v] = values[node] + 1;  
        }
      }
  }
 
  return minMST;   
}
 
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    
    vector<int> adj[graph_nodes + 1];
    for(int i = 0; i < graph_from.size(); i++) {
        adj[graph_from[i]].push_back(graph_to[i]);
        adj[graph_to[i]].push_back(graph_from[i]);
    }
    
    int MST = INT_MAX;
    
    for(long i = 0; i < ids.size(); i++) {
        if(ids[i] == val) {
            int value = BFS(i+1, ids, adj, val);
            MST = value < MST ? value : MST;
        }
    }
    
    return MST < INT_MAX ? MST : -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}



