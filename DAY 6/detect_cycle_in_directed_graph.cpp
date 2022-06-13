bool DFS(vector<int> adj[], vector<bool>&recStack, int source, vector<bool>& visited) {
    visited[source] = true;
    recStack[source] = true;
    // go to adjacent cells
    for (auto nbr : adj[source]) {
        if (!visited[nbr] && DFS(adj, recStack, nbr, visited)) {
            return true;
        }
        if (recStack[nbr]) {
            return true;
        }
    }
    recStack[source] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n + 1];
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
    }

    vector<bool> recStack(n + 1, false);
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (DFS(adj, recStack, i, visited)) return true;
        }
    }

    return false;
}