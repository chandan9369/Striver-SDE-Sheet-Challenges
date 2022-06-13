#include<bits/stdc++.h>
using namespace std;
// ------------------------------------------- Code Start Here ------------------------------------------------------
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>>b) {
	return a.first < b.first;
}
int find(int u, vector<int> & parent) {
	if (parent[u] == -1) return u;
	return find(parent[u], parent);
}

bool union_sets(int u, int v, vector<int> & parent) {
	int s1 = find(u, parent);
	int s2 = find(v, parent);

	if (s1 == s2) return true;
	else {
		parent[s2] = s1;
	}
	return false;
}
void solve() {
	int n;
	cin >> n;
	vector<pair<int, pair<int, int>>> edges = {
		{10, {0, 1}}, {15, {1, 2}}, {5, {0, 2}}, {2, {3, 1}}, {40, {3, 2}}
	};

	int cost = 0;
	vector<int> parents(n, -1);

	// sort the given edges with weights
	sort(begin(edges), end(edges), cmp);
	for (auto edge : edges) {
		int w = edge.first;
		int u = edge.second.first;
		int v = edge.second.second;

		// now check whether with this edge we have cycle or not
		if (!union_sets(u, v, parents)) {
			cost += w;
		}
	}
	cout << "Cost to build minimum spanning tree using kruskal's algorithm : " << cost << endl;

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