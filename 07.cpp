#include <bits/stdc++.h>

using namespace std;

const int N = 3123;

int n, m;
bool vis[N];
vector <int> adj[N];
int occ[N];

int ans = 0;

inline int nc2(int x) {
	return (x*(x - 1))/2;
}

void dfs(int u) {
	memset(occ, 0, sizeof occ);

	for (int v: adj[u])
		for (int w: adj[v])
			occ[w]++;

	for (int i = 1; i <= n; i++)
		if (i != u)
			ans += nc2(occ[i]);

	for (int v: adj[u])
		if (!vis[v])
			vis[v] = 1, dfs(v);
}

int main() {
	ios::sync_with_stdio(0);

	memset(vis, 0, sizeof vis);

	cin>>n>>m;
	while (m--) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	for (int u = 1; u <= n; u++)
		if (!vis[u])
			vis[u] = 1, dfs(u);

	cout<<ans<<endl;
	return 0;
}