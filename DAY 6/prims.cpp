#include<bits/stdc++.h>
using namespace std;
// ------------------------------------------- Code Start Here ------------------------------------------------------

class Graph {
	vector<pair<int, int>> * adj;
	int V;
public:
	Graph(int v) {
		V = v;
		adj = new vector<pair<int, int>>[v];
	}
	void addEdge(int u, int v, int weight) {
		adj[u].push_back({v, weight});
		adj[v].push_back({u, weight});
	}
	void print() {
		for (int i = 0; i < V; i++) {
			cout << i << " --> ";
			for (auto nbr : adj[i]) {
				cout << "{" << nbr.first << "," << nbr.second << "}" << endl;
			}
			cout << endl;
		}
		cout << endl;
	}
	void prims() {
		vector<int> key(V, INT_MAX);
		vector<bool> MST(V, false);
		int source = 0;

		key[source] = 0;

		for (int i = 0; i < V; i++) {
			// find the minimum key vertex which is not present in the MST
			int u = -1;
			for (int i = 0; i < V; i++) {
				if (!MST[i] and (u == -1 || (key[u] > key[i]))) {
					u = i;
				}
			}

			// include this vertex in MST
			MST[u] = true;

			// now update the key array for adjacent vertex
			for (auto nbr : adj[u]) {
				int v = nbr.first;
				int w = nbr.second;
				if (!MST[v] and (key[v] > w)) {
					key[v] = w;
				}
			}
		}

		for (int i = 0; i < V; i++) {
			if (MST[i]) {
				cout << i << " ";
			}
		}
		cout << endl;
		int cost = 0;
		for (auto w : key) {
			cost += w;
		}
		cout << "Cost to build minimum spanning tree using key array : " << cost << endl;
	}

	// prims algorithm using heap data structure
	void primsHeap() {
		vector<bool> MST(V, false);
		int source = 0;
		int weight = 0;
		int cost = 0;

		priority_queue < pair<int, int>, vector < pair<int, int>>, greater<pair<int, int>>> q;
		q.push({weight, source});

		for (int i = 0; i < V; i++) {
			// node with minimum weight will be picked through heap
			auto node = q.top();
			q.pop();

			source = node.second;
			weight = node.first;

			// check whether this vertex is visited or not
			if (MST[source]) continue;

			// now add this vertex to MST and add cost also
			cost += weight;
			MST[source] = true;

			// now add the adjacent vertex to heap
			for (auto nbr : adj[source]) {
				int v = nbr.first;
				int w = nbr.second;
				if (!MST[v]) {
					q.push({w, v});
				}
			}
		}
		cout << "Cost to build minimum spanning tree using heap : " << cost << endl;
	}

};
void solve() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> edges = {
		{2, {0, 2}}, {1, {0, 1}}, {4, {3, 4}},
		{5, {0, 3}}, {8, {1, 2}}, {2, {1, 4}}, {3, {2, 3}}
	};
	Graph g(n);
	for (auto edge : edges) {
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		g.addEdge(u, v, w);
	}

	cout << "Graph\n";
	g.print();

	g.prims();
	g.primsHeap();
}


// ------------------------------------------- Code Ends Here -------------------------------------------------------

int main() {

// ------------------------------------------------------------------------------------------------------------------
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

// ------------------------------------------------------------------------------------------------------------------

	int t = 1;
	// cin >> t;
	while (t--) solve();
}