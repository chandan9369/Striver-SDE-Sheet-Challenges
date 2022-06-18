#include<bits/stdc++.h>


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> parent(n + 1, -1);
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto nbr : adj[node]) {
                    if (!visited[nbr]) {
                        visited[nbr] = true;
                        parent[nbr] = node;
                        q.push(nbr);
                    }
                    else if (nbr != parent[node]) {
                        return "Yes";
                    }
                }
            }
        }
    }
    return "No";
}

