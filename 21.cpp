#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector <int> a, dp;

int main() {
	ios::sync_with_stdio(0);
	
	cin>>n>>m;
	a.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		double tmp;
		cin>>a[i]>>tmp;	
	}
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] <= a[i])
				dp[i] = max(dp[i], dp[j] + 1);
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);

	cout<<(n - ans)<<endl;
	return 0;
}