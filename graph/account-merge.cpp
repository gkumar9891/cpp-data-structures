// https://www.geeksforgeeks.org/problems/account-merge/1
#include <bits/stdc++.h>
#include "../ctemplate.h"

int findParent(int node, vector<int> &parent) {
    if(parent[node] == node) {
        return node;
    }

    return findParent(parent[node], parent);
}

void makeUnion(int i, int j, vector<int> &parent, vector<int> &rank) {
    int u = findParent(i, parent);
    int v = findParent(j, parent);

    if(u == v) {
        return;
    }

    if(rank[u] < rank[v]) {
        parent[u] = v;
    }  else if(rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    map<string, int> mp;
    map<int, vector<string>> mp2;

    vector<int> parent(accounts.size());
    for(int i = 0; i < parent.size(); i++) {
        parent[i] = i;
    }

    vector<int> rank(accounts.size(), 0);


    for(int i = 0; i < accounts.size(); i++) {
        for(int j = 1; j < accounts[i].size(); j++) {
            string str = accounts[i][j];

            if(mp.find(str) == mp.end()) {
                mp[str] = i;
            } else {
                int u = mp[str];
                int v = i;

                makeUnion(u, v, parent, rank);
            }
        }
    }

    for(auto it : mp) {
        int p = findParent(it.second);

        if(mp2.find(p) == mp2.end()) {
            mp2[p].push_back(accounts[p][0]);
        }

        mp2[p].push_back(it.first);
    }

    vector<vector<string>> ans;
    for(auto it : mp2) {
        ans.push_back(it.second);
    }

    return ans;


}

int main() {

    int n;
    read(n);

    vector<vector<string>> accounts;
    for(int i = 0; i < n; i++) {
        vector<string> temp;
        int x;
        read(x);

        for(int j = 0; j < x; j++) {
            string s1;
            read(s1);
            temp.push_back(s1);
        }

        accounts.push_back(temp);
    }

    write(accountsMerge(accounts));
    return 0;
}