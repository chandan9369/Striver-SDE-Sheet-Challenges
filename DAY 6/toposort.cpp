#include<bits/stdc++.h>
void DFS(vector<int> adj[], int source, vector<bool> &visited, list<int>&sample) {
    visited[source] = true;

    // traversing adjacent nodes
    for (auto nbr : adj[source]) {
        if (!visited[nbr]) {
            DFS(adj, nbr, visited, sample);
        }
    }
    // case where we do not have any remaining task to do
    sample.push_front(source);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    list<int> sample;
    vector<bool> visited(v, false);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            DFS(adj, i, visited, sample);
        }
    }

    vector<int> ans;
    // copy sample into a vector
    for (auto ele : sample) {
        ans.push_back(ele);
    }
    return ans;
}