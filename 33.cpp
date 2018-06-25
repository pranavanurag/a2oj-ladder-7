#include <bits/stdc++.h>

using namespace std;

#define INF 12345678

const int N = 312345;
const int K = log2(N) + 1;

int n, a[N], k;

struct node {
	int rmin, rgcd;
};

node table[N][K];

void build() {
	for (int i = 1; i <= n; i++)
		table[i][0].rmin = table[i][0].rgcd = a[i];
	k = log2(n);

	for (int j = 1; j <= k; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++) {
			table[i][j].rmin = min(table[i][j - 1].rmin, table[i + (1 << (j - 1))][j - 1].rmin);
			table[i][j].rgcd = __gcd(table[i][j - 1].rgcd, table[i + (1 << (j - 1))][j - 1].rgcd);
		}
}

node query(int l, int r) {
	int len = r - l + 1;
	int x = log2(len);

	node ans;
	ans.rmin = min(table[l][x].rmin, table[r - (1 << x) + 1][x].rmin);
	ans.rgcd = __gcd(table[l][x].rgcd, table[r - (1 << x) + 1][x].rgcd);
	return ans;
}

int rminq(int l, int r) {
	return query(l, r).rmin;
}

int rgcdq(int l, int r) {
	return query(l, r).rgcd;
}

bool can(int len) {
	for (int i = 1; i <= n - len + 1; i++)
		if (rminq(i, i + len - 1) == rgcdq(i, i + len - 1))
			return 1;
	return 0;
}

vector <int> ans;

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	build();

	int low = 1, high = n;
	while (low < high) {
		int mid = (low + high + 1)/2;
		if (can(mid))
			low = mid;
		else
			high = mid - 1;
	}

	for (int i = 1; i <= n - low + 1; i++)
		if (rminq(i, i + low - 1) == rgcdq(i, i + low - 1))
			ans.push_back(i);

	cout<<ans.size()<<" "<<(low - 1)<<endl;
	for (int x: ans)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}