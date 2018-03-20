#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)1e9 + 7)

const ll N = (ll)1e5;

ll t, k, a, b;
ll dp[N + 1], pre[N + 1];

void pre_calc() {
	dp[0] = 1;
	for (ll i = 1; i < k; i++)
		dp[i] = 1;
	for (ll i = k; i <= N; i++)
		dp[i] = (dp[i - 1] + dp[i - k])%mod;

	pre[0] = 0;
	for (ll i = 1; i <= N; i++) {
		pre[i] = (pre[i - 1] + dp[i])%mod;
	}
}

ll sumq(ll l, ll r) {
	ll ans = pre[r] - pre[l - 1];
	if (ans < 0)
		return ans + mod;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin>>t>>k;
	pre_calc();

	while (t--) {
		cin>>a>>b;
		cout<<sumq(a, b)<<endl;
	}
	return 0;
}