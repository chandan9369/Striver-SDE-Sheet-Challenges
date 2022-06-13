#include <bits/stdc++.h>
using namespace std;

bool DFS(vector<int> graph[], int n, vector<int> &visited, int parent, int source, int color) {
	visited[source] = color;

	for (auto nbr : graph[source]) {
		if (visited[nbr] == 0) {
			// here we are using 3-color for flipping colors
			int subProb = DFS(graph, n, visited, source, nbr, 3 - color);
			// case where we have odd length cycle
			if (!subProb)
				return false;
		}
		else if (nbr != parent and color == visited[nbr]) {
			return false;
		}
	}
	return true;
}
bool bfs(int src, vector<vector<int>>& graph, vector<int> &color) {
	color[src] = 1;
	queue<int> q;
	q.push(src);

	while (!q.empty()) {
		int u = q.front();
		q.pop();


		for (auto i : graph[u]) {
			if ( color[i] == -1) {
				//Assign alternate color to its neighbors.
				color[i] = 1 - color[u];
				q.push(i);
			}
			else if (color[i] == color[u])return false; // If neighbor is of same color returnn false.
		}
	}
	return true;
}
bool isBipartite(vector<int> graph[], int n) {
	// we have 0 for unvisited nodes, and for visited node's , we have
	// 1 for set1's color and 2 for set2's color
	vector<int> visited(n, 0);
	int parent = -1;

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			if (!DFS(graph, n, visited, parent, i, 1)) return false;
		}
	}
	return true;
}
int main()
{
	vector<vector<int>> edges{{0, 1}, {0, 4}, {0, 5}, {1, 2}, {2, 3}};
	vector<int> adj[6];
	for (auto edge : edges) {
		int x = edge[0];
		int y = edge[1];
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	return 0;
};