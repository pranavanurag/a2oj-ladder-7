#include <bits/stdc++.h>

using namespace std;

#define mod ((long long)1e9 + 7)
#define k (256)

long long fast_exp_mod(long long x, long long a) {
	long long ans = 1, current = x;
	while (a > 0) {
		if (a%2 == 1)
			ans = (ans*current)%mod;
		a /= 2;
		current = (current*current)%mod;
	}
	return ans;
}

long long inv_mod(long long x) {
	return fast_exp_mod(x, mod - 2);
}

const int N = 123456;

long long kpow[N];

void pre() {
	kpow[0] = 1;
	for (int i = 1; i < N; i++)
		kpow[i] = (kpow[i - 1]*k)%mod;
}

string s, t;
int n, m;
vector <long long> ph;
long long thash;
vector <int> idx;

void compute_ph() {
	ph.resize(n);
	ph[0] = s[0];
	for (int i = 1; i < n; i++)
		ph[i] = (ph[i - 1] + (s[i]*kpow[i])%mod)%mod;
}

long long h(int i, int j) {
	if (i == 0)
		return ph[j];
	return (((ph[j] - ph[i - 1] + mod)%mod)*inv_mod(kpow[i]))%mod;
}

bool is_good_idx(int i) {
	return binary_search(idx.begin(), idx.end(), i);
}

long long dp[N], sdp[N], ssdp[N];

int main() {
	ios::sync_with_stdio(0);

	pre();

	cin>>s>>t;
	n = s.size();
	m = t.size();

	compute_ph();

	thash = t[0];
	for (int i = 1; i < m; i++)
		thash = (thash + (t[i]*kpow[i])%mod)%mod;

	for (int i = 0; i < n - m + 1; i++)
		if (h(i, i + m - 1) == thash)
			idx.push_back(i);

	memset(dp, 0, sizeof dp);
	memset(sdp, 0, sizeof sdp);
	memset(ssdp, 0, sizeof ssdp);

	for (int i = n - 1; i >= 0; i--) {
		if (is_good_idx(i))
			dp[i] = (ssdp[i + m] + (n - (i + m - 1) + mod))%mod;
		else
			dp[i] = dp[i + 1];

		sdp[i] = (sdp[i + 1] + dp[i])%mod;
		ssdp[i] = (ssdp[i + 1] + sdp[i])%mod;
	}

	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans = (ans + dp[i])%mod;

	cout<<ans<<endl;
	return 0;
}