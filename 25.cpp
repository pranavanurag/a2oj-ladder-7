#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

string tmp;

int n, m;
int start_i, start_j, end_i, end_j;
int a[N][N], sde[N][N];
bool vis[N][N];

inline void visit_neighbour(int vi, int vj, int i, int j, queue <pair <int, int> > &q) {
	vis[vi][vj] = 1;
	sde[vi][vj] = min(sde[vi][vj], sde[i][j] + 1);
	q.push({vi, vj});
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for (int i = 0; i < n; i++) {
		cin>>tmp;
		for (int j = 0; j < m; j++) {
			if (tmp[j] == '0')
				a[i][j] = 0;
			else if (tmp[j] == 'T')
				a[i][j] = -1;
			else if (tmp[j] == 'S')
				start_i = i, start_j = j;
			else if (tmp[j] == 'E')
				end_i = i, end_j = j;
			else
				a[i][j] = tmp[j] - '0';
		}
	}

	memset(sde, N*N, sizeof sde);
	memset(vis, 0, sizeof vis);

	queue <pair <int, int> > q;
	q.push({end_i, end_j});
	vis[end_i][end_j] = 1;
	sde[end_i][end_j] = 0;
	while (!q.empty()) {
		pair <int, int> u = q.front();
		q.pop();

		int i = u.first, j = u.second;
		if (i < n - 1 && a[i + 1][j] != -1 && !vis[i + 1][j])
			visit_neighbour(i + 1, j, i, j, q);
		if (i > 0 && a[i - 1][j] != -1 && !vis[i - 1][j])
			visit_neighbour(i - 1, j, i, j, q);
		if (j < m - 1 && a[i][j + 1] != -1 && !vis[i][j + 1])
			visit_neighbour(i, j + 1, i, j, q);
		if (j > 0 && a[i][j - 1] != -1 && !vis[i][j - 1])
			visit_neighbour(i, j - 1, i, j, q);
	}

	int ans = 0, mv = sde[start_i][start_j];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (sde[i][j] <= mv && a[i][j] != -1)
				ans += a[i][j];
		}
	}

	cout<<ans<<endl;
	return 0;
}