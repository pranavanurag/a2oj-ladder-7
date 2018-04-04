#include <bits/stdc++.h>

using namespace std;

const int N = 234567;

int n;
long long a[N];
long long dp[2][N];
bool vis[2][N];

void dfs(int u, bool type) {
	int v = u;
	if (type)
		v += a[u];
	else
		v -= a[u];

	if (v <= 0 || v > n) {
		dp[type][u] = a[u];
		return;
	}

	if (!vis[!type][v]) {
		vis[!type][v] = 1;
		dfs(v, !type);
	}
	else {
		if (dp[!type][v] == 0)
			dp[!type][v] = -1;

		if (dp[!type][v] == -1)
			dp[type][u] = -1;
		else
			dp[type][u] = a[u] + dp[!type][v];

		return;
	}

	if (dp[!type][v] == -1)
		dp[type][u] = -1;
	else
		dp[type][u] = a[u] + dp[!type][v];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for (int i = 2; i <= n; i++)
		cin>>a[i];

	vis[0][1] = 1, vis[1][1] = 1;
	dp[0][1] = -1, dp[1][1] = -1;
	for (int type = 0; type <= 1; type++)
		for (int u = 2; u <= n; u++)
			if (!vis[type][u])
				vis[type][u] = 1, dfs(u, type);

	for (int u = 2; u <= n; u++)
		if (dp[0][u] == -1)
			cout<<-1<<endl;
		else
			cout<<(u - 1 + dp[0][u])<<endl;

	return 0;
}