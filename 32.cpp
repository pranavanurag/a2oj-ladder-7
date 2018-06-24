#include <bits/stdc++.h>

using namespace std;

#define mod ((long long)(1e9 + 7))

const int N = 2345;

int d, n, a[N];
bool vis[N];
vector <int> adj[N];

long long dfs(int u, int src) {
	long long ans = 1;
	for (int v: adj[u])
		if (!vis[v])
			if (a[src] <= a[v] && a[v] <= a[src] + d) {
				if (a[src] == a[v] && src > v)
					continue;
				vis[v] = 1;
				ans = (ans * (dfs(v, src) + 1))%mod;
			}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	cin>>d>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	long long ans = 0;
	for (int u = 1; u <= n; u++) {
		memset(vis, 0, sizeof vis);
		vis[u] = 1;
		ans = (ans + dfs(u, u))%mod;
	}

	cout<<ans<<endl;

	return 0;
}