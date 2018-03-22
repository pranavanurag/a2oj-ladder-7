#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int spf[N];

void pre() {
	for (int i = 2; i < N; i++)
		spf[i] = i;
	for (int i = 2; i*i < N; i++)
		if (spf[i] == i)
			for (int j = i*i; j < N; j += i)
				spf[j] = i;
}

int dp[N], d[N];
int n, a[N];

vector <int> prime_factors(int x) {
	vector <int> ans;
	while (x > 1) {
		int f = spf[x];
		ans.push_back(f);
		while (x%f == 0)
			x /= f;
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	memset(dp, 0, sizeof dp);
	memset(d, 0, sizeof d);

	pre();

	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	for (int i = 1; i <= n; i++) {
		int curr = a[i];
		for (int el: prime_factors(curr))
			dp[i] = max(dp[i], d[el] + 1);
		for (int el: prime_factors(curr))
			d[el] = max(d[el], dp[i]);
	}

	int ans = 1;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);

	cout<<ans<<endl;
	return 0;
}