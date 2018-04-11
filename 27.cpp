#include <bits/stdc++.h>

using namespace std;

const int N = 1234;
const int K = 1234567;

long long n, m, k, p;
long long a[N][N];
long long r[K], c[K];
multiset <long long, greater <long long> > rs, cs;

void pre() {
	for (int i = 0; i < n; i++) {
		long long curr = 0;
		for (int j = 0; j < m; j++)
			curr += a[i][j];

		rs.insert(curr);
	}

	for (int j = 0; j < m; j++) {
		long long curr = 0;
		for (int i = 0; i < n; i++)
			curr += a[i][j];

		cs.insert(curr);
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m>>k>>p;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin>>a[i][j];

	pre();

	c[0] = 0;
	for (int ci = 1; ci <= k; ci++) {
		auto it = cs.begin();
		long long curr = *it;

		c[ci] = c[ci - 1] + curr;
		cs.erase(it);
		cs.insert(curr - n*p);
	}

	r[0] = 0;
	for (int ri = 1; ri <= k; ri++) {
		auto it = rs.begin();
		long long curr = *it;

		r[ri] = r[ri - 1] + curr;
		rs.erase(it);
		rs.insert(curr - m*p);
	}


	long long ans = c[k];
	for (int ri = 1; ri <= k; ri++)
		ans = max(ans, r[ri] + c[k - ri] - ri*(k - ri)*p);

	cout<<ans<<endl;

	return 0;
}