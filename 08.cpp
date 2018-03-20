#include <bits/stdc++.h>

using namespace std;

#define mod ((int)(1e8))

const int N = 123;
const int K = 12;

int memo[N][N][K][2];

int dp(int n1, int n2, int streak, int type, int k1, int k2) {
	if (memo[n1][n2][streak][type] != -1)
		return memo[n1][n2][streak][type];

	int ans = 0;

	if (n1 == 0)
		ans = (n2 <= k2 && streak == n2);
	else if (n2 == 0)
		ans = (n1 <= k1 && streak == n1);

	else {
		if (type == 0) {
			if (streak > n1)
				ans = 0;
			else
				for (int x = 1; x <= k2; x++)
					ans = (ans + dp(n1 - streak, n2, x, !type, k1, k2))%mod;
		}
		else {
			if (streak > n2)
				ans = 0;
			else
				for (int x = 1; x <= k1; x++)
					ans = (ans + dp(n1, n2 - streak, x, !type, k1, k2))%mod;
		}
	}

	// cout<<"dp("<<n1<<", "<<n2<<", "<<streak<<", "<<type<<", "<<k1<<", "<<k2<<") = "<<ans<<endl;
	
	memo[n1][n2][streak][type] = ans;
	return ans;
}

int n1, n2, k1, k2;

int main() {
	ios::sync_with_stdio(0);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < K; k++)
				memo[i][j][k][0] = memo[i][j][k][1] = -1;

	cin>>n1>>n2>>k1>>k2;
	int ans = 0;
	for (int x = 1; x <= k1; x++)
		ans = (ans + dp(n1, n2, x, 0, k1, k2))%mod;
	for (int x = 1; x <= k2; x++)
		ans = (ans + dp(n1, n2, x, 1, k1, k2))%mod;

	cout<<ans<<endl;
	return 0;
}