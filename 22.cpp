#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 234567;
const int H = 789;

int dp_prev[N], dp_curr[N];
int r, g;

int main() {
	ios::sync_with_stdio(0);

	memset(dp_prev, 0, sizeof dp_prev);

	cin>>r>>g;

	int h = 0, curr = 0;
	while (curr <= (r + g)) {
		h++;
		curr += h;
	}
	h--;

	if (r)
		dp_curr[1] = 1;
	if (g)
		dp_curr[0] = 1;

	curr = 1;
	for (int hi = 2; hi <= h; hi++) {

		for (int ri = 0; ri <= r; ri++)
			dp_prev[ri] = dp_curr[ri];
		memset(dp_curr, 0, sizeof dp_curr);

		curr += hi;
		for (int ri = 0; ri <= r; ri++) {
			if (ri >= hi)
				dp_curr[ri] = (dp_curr[ri] + dp_prev[ri - hi])%mod;
			if (curr - ri >= hi)
				dp_curr[ri] = (dp_curr[ri] + dp_prev[ri])%mod;
		}

	}

	int ans = 0;
	for (int ri = 0; ri <= r; ri++)
		if (curr - ri <= g)
			ans = (ans + dp_curr[ri])%mod;

	cout<<ans<<endl;
	return 0;
}