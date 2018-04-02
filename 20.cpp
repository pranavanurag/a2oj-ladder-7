#include <bits/stdc++.h>

using namespace std;

const int N = 2234567;

vector <int> lt, a;
int n, M = 0;

int main() {
	ios::sync_with_stdio(0);

	lt.resize(N);
	cin>>n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin>>a[i];
	sort(a.begin(), a.end());

	for (int j = 0; j <= a[0]; j++)
		lt[j] = -1;
	if (n > 1)
		for (int i = 0; i < n - 1; i++)
			for (int curr = a[i] + 1; curr <= a[i + 1]; curr++)
				lt[curr] = a[i];
	M = a[n - 1];
	for (int curr = M + 1; curr <= 2*M; curr++)
		lt[curr] = M;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && a[i] == a[i - 1])
			continue;
		for (int x = 2*a[i]; x <= 2*M; x += a[i])
			ans = max(ans, lt[x]%a[i]);
	}

	cout<<ans<<endl;
	return 0;
}