#include <bits/stdc++.h>

using namespace std;

const long long N = 64;

long long l, r, n;
long long memo[N][2][2][2][2];
long long bl[N], br[N];

void make_bin(long long x, long long bx[N]) {
	long long i = 0;
	while (x > 0) {
		bx[i++] = x%2;
		x /= 2;
	}
	n = max(n, i);
}

long long dp(long long i, long long xl, long long xr, long long yl, long long yr) {
	if (i == -1)
		return 0;

	if (memo[i][xl][xr][yl][yr] != -1)
		return memo[i][xl][xr][yl][yr];

	bool x0 = (bl[i] == 0) || xl;
	bool x1 = (bl[i] == 1) || xr;
	bool y0 = (br[i] == 0) || yl;
	bool y1 = (br[i] == 1) || yr;

	long long ans = 0;
	if (x0 && y0)
		ans = max(ans, dp(i - 1, xl, (xr || br[i] == 1), yl, (yr || br[i] == 1)));
	if (x0 && y1)
		ans = max(ans, (1LL << i) + dp(i - 1, xl, (xr || br[i] == 1), (yl || bl[i] == 0), yr));
	if (x1 && y0)
		ans = max(ans, (1LL << i) + dp(i - 1, (xl || bl[i] == 0), xr, yl, (yr || br[i] == 1)));
	if (x1 && y1)
		ans = max(ans, dp(i - 1, (xl || bl[i] == 0), xr, (yl || bl[i] == 0), yr));

	memo[i][xl][xr][yl][yr] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	memset(memo, -1, sizeof memo);
	memset(bl, 0, sizeof bl);
	memset(br, 0, sizeof br);
	n = 0;

	cin>>l>>r;

	make_bin(l, bl);
	make_bin(r, br);

	cout<<dp(n - 1, 0, 0, 0, 0)<<endl;
	return 0;
}