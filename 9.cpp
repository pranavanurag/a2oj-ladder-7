#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector <int> adj[N];
int n, m, c[N];
map <int, bool> occ;
map <int, set <int> > h;

bool vis[N];

void dfs(int u) {
	occ[c[u]] = 1;

	for (int v: adj[u])
		if (c[u] != c[v])
			h[c[u]].insert(c[v]);

	for (int v: adj[u])
		if (!vis[v])
			vis[v] = 1, dfs(v);
}

int main() {
	ios::sync_with_stdio(0);

	memset(vis, 0, sizeof vis);

	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		cin>>c[i];
	while (m--) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int u = 1; u <= n; u++)
		if (!vis[u])
			vis[u] = 1, dfs(u);

	int ans = -1, best = -1;
	for (int i = 1; i <= N; i++) {
		if (occ.count(i)) {
			int curr = h[i].size();
			if (best < curr)
				best = curr, ans = i;
		}
	}

	cout<<ans<<endl;
	return 0;
}