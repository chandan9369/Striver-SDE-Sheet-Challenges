#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define F first
#define S second
#define pb push_back
#define pi pair<int, int>
#define vi vector<int>
#define vpi vector<pi>
#define pair_que_min priority_queue<pi, vpi, greater<pi>>
#define pair_que_max priority_queue<pi>
#define que_max priority_queue<int>
#define que_min priority_queue<int, vi, greater<int>>
#define print(a)          \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print1(a)    \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
            x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

// ------------------------------------------- Code Start Here ------------------------------------------------------
vector<int> bellmanFord(int n, vector<vector<int>> &edges, int source)
{
    // array to contain distances of every node from source vertex
    vector<int> dist(n, INT_MAX);

    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // relax the all edges
        for (auto edge : edges)
        {
            int node = edge[0];
            int nbr = edge[1];
            int weight = edge[2];
            // relaxing the edge on the basis of below condition
            if (dist[nbr] > dist[node] + weight)
            {
                dist[nbr] = dist[node] + weight;
            }
        }
    }

    // so if graph does not contain negative weight then we get our result
    // by above looping for (n-1) times as maximum height of edges we can get is
    // (n-1) that is why we are running the loop for (n-1) times and this algo
    // has time compelexity O(n*E).

    // this loop is to check whether we have negative weight or not
    for (auto edge : edges)
    {
        int node = edge[0];
        int nbr = edge[1];
        int weight = edge[2];
        if (dist[nbr] > dist[node] + weight)
        {
            cout << "~~~~~~~ Graph contain negative weight cycle. ~~~~~~~" << endl;
            exit(0);
        }
    }
    return dist;
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
    // numbe of vertices
    int n;
    cin >> n;
    // number of edges
    int e;
    cin >> e;

    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        vector<int> edge;
        int u, v, w;
        cin >> u >> v >> w;
        edge.pb(u);
        edge.pb(v);
        edge.pb(w);
        edges.push_back(edge);
    }

    int src = 0;
    cin >> src;

    vector<int> distances = bellmanFord(n, edges, src);

    for (int i = 0; i < n; i++)
    {
        if (i != src)
        {
            cout << "distance of " << i << " from " << src << " : " << distances[i] << endl;
        }
    }
    return 0;

}