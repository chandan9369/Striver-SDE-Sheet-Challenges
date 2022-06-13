#include<bits/stdc++.h>
using namespace std;


#define ll            long long int
#define F              first
#define S              second
#define pb             push_back
#define pi             pair<int,int>
#define vi             vector<int>
#define vpi            vector<pi>
#define pair_que_min   priority_queue <pi, vpi, greater<pi>>
#define pair_que_max   priority_queue <pi>
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
	int x = 1;
	while (b)
	{
		if (b & 1) x *= a;
		a *= a;
		b >>= 1;
	}
	return x;
}

// ------------------------------------------- Code Start Here ------------------------------------------------------
void dfs(vector<int> adj[], int src, vector<bool> & visited, vector<int> &ans) {
	visited[src] = true;
	ans.push_back(src);
	for (auto nbr : adj[src]) {
		if (!visited[nbr]) {
			dfs(adj, nbr, visited, ans);
		}
	}
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
	vector<int> adj[V];
	for (auto edge : edges) {
		adj[edge[0]].push_back(edge[1]);
		adj[edge[1]].push_back(edge[0]);
	}
	vector<bool> visited(V, false);
	vector<vector<int>> ans;
	for (int i = 0; i < V; i++) {
		vector<int> temp;
		if (!visited[i]) {
			dfs(adj, i, visited, temp);
		}
		if (!temp.empty())
			ans.push_back(temp);
	}
	return ans;
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