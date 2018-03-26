#include <bits/stdc++.h>

using namespace std;

const int N = 1234;

int n, m, w[N][N];
long long dp[5][N][N];

void pre1() {
	dp[1][1][1] = w[1][1];
	for (int i = 2; i <= n; i++)
		dp[1][i][1] = dp[1][i - 1][1] + w[i][1];	
	for (int j = 2; j <= m; j++)
		dp[1][1][j] = dp[1][1][j - 1] + w[1][j];

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= m; j++)
			dp[1][i][j] = w[i][j] + max(dp[1][i - 1][j], dp[1][i][j - 1]);
}

void pre2() {
	dp[2][n][m] = w[n][m];
	for (int i = n - 1; i >= 1; i--)
		dp[2][i][m] = dp[2][i + 1][m] + w[i][m];
	for (int j = m - 1; j >= 1; j--)
		dp[2][n][j] = dp[2][n][j + 1] + w[n][j];

	for (int i = n - 1; i >= 1; i--)
		for (int j = m - 1; j >= 1; j--)
			dp[2][i][j] = w[i][j] + max(dp[2][i + 1][j], dp[2][i][j + 1]);
}

void pre3() {
	dp[3][n][1] = w[n][1];
	for (int i = n - 1; i >= 1; i--)
		dp[3][i][1] = dp[3][i + 1][1] + w[i][1];
	for (int j = 2; j <= m; j++)
		dp[3][n][j] = dp[3][n][j - 1] + w[n][j];

	for (int i = n - 1; i >= 1; i--)
		for (int j = 2; j <= m; j++)
			dp[3][i][j] = w[i][j] + max(dp[3][i + 1][j], dp[3][i][j - 1]);
}

void pre4() {
	dp[4][1][m] = w[1][m];
	for (int i = 2; i <= n; i++)
		dp[4][i][m] = dp[4][i - 1][m] + w[i][m];
	for (int j = m - 1; j >= 1; j--)
		dp[4][1][j] = dp[4][1][j + 1] + w[1][j];

	for (int i = 2; i <= n; i++)
		for (int j = m - 1; j >= 1; j--)
			dp[4][i][j] = w[i][j] + max(dp[4][i - 1][j], dp[4][i][j + 1]);
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin>>w[i][j];

	pre1();
	pre2();
	pre3();
	pre4();
	
	long long ans = 0;
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= m - 1; j++) {
			ans = max(ans, dp[1][i - 1][j] + dp[2][i + 1][j] + dp[3][i][j - 1] + dp[4][i][j + 1]);
			ans = max(ans, dp[1][i][j - 1] + dp[2][i][j + 1] + dp[3][i + 1][j] + dp[4][i - 1][j]);
		}
	}

	cout<<ans<<endl;
	return 0;
}