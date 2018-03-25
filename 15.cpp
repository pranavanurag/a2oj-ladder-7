#include <bits/stdc++.h>

using namespace std;

const long long N = 512;
const long long INF = 25*1e9;

long long n, w[N][N], x[N];
long long d[N][N];
vector <long long> ans;

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			cin>>w[i][j];
	for (long long i = 1; i <= n; i++)
		cin>>x[i];

	memset(d, 0, sizeof d);
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= n; j++)
			d[i][j] = w[i][j];

	for (long long k = n; k >= 1; k--) {
		long long u = x[k];

		for (long long i = 1; i <= n; i++)
			for (long long j = 1; j <= n; j++)
				d[i][j] = min(d[i][j], d[i][u] + d[u][j]);

		long long curr = 0;
		for (long long k_i = n; k_i >= k; k_i--) {
			for (long long k_j = n; k_j >= k; k_j--) {
				long long u = x[k_i], v = x[k_j];
				curr += d[u][v];
			}
		}
		ans.push_back(curr);
	}

	reverse(ans.begin(), ans.end());
	for (long long el: ans)
		cout<<el<<" ";
	cout<<endl;
	return 0;
}