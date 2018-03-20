#include <bits/stdc++.h>

using namespace std;

#define mod ((long long)(1e9 + 7))

const long long N = 2123;

long long n, k;
long long memo[N][N];

long long dp(long long fe, long long len) {
	if (memo[fe][len])
		return memo[fe][len];

	long long ans = 0;
	if (len == 1)
		ans = 1;
	else {
		for (long long se = fe; se <= n; se += fe) {
			ans = (ans + dp(se, len - 1))%mod;
		}
	}

	memo[fe][len] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	for (long long i = 0; i < N; i++) {
		for (long long j = 0; j < N; j++)
			memo[i][j] = 0;
	}
	cin>>n>>k;
	
	long long ans = 0;
	for (long long i = 1; i <= n; i++) 
		ans = (ans + dp(i, k))%mod;

	cout<<ans<<endl;
	return 0;
}