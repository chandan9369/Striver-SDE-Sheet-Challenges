#include<bits/stdc++.h>

bool detectCycleInDirectedGrap(vector<vector<int>> &edges, int v)  {
    vector<int> adj[v];
    for (auto edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> indegree(v, 0);
    for (int i = 0; i < v; i++) {
        for (auto nbr : adj[i]) {
            indegree[nbr]++;
        }
    }

    queue<int> q;
    for (int node = 0; node < v; node++) {
        if (indegree[node] == 0) {
            q.push(node);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for (auto nbr : adj[node]) {
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    return count != v;
}