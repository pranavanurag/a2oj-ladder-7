#include <bits/stdc++.h>

using namespace std;

int n;
vector <double> v;

int main() {
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(12);

	cin>>n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin>>v[i];

	sort(v.rbegin(), v.rend());
	double ans = v[0], curr_p = (1 - v[0]), curr_s = v[0]/(1 - v[0]), curr = v[0];
	for (int i = 1; i < n; i++) {
		curr += curr_p*(1 - curr_s)*v[i];
		ans = max(ans, curr);

		curr_p *= 1 - v[i], curr_s += v[i]/(1 - v[i]);
	}

	cout<<ans<<endl;
	return 0;
}