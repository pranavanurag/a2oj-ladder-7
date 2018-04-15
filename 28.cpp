#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector <int> adj[N];
int n;
long long v[N];

pair <long long, long long> dfs(int u, int par) {
	pair <long long, long long> ans;
	ans = {0, 0};

	for (int v: adj[u]) {
		pair <long long, long long> curr;
		if (par != v)
			curr = dfs(v, u);

		ans.first = max(ans.first, curr.first);
		ans.second = max(ans.second, curr.second);
	}

	long long d = v[u] + ans.first - ans.second;
	if (d < 0)
		ans.first += -d;
	else
		ans.second += d;

	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		cin>>v[i];

	pair <long long, long long> ans = dfs(1, -1);
	cout<<ans.first + ans.second<<endl;

	return 0;
}