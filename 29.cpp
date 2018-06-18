#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

string s;
int n, pi[N], h[N];
vector <pair <int, int> > ans;

int main() {
	ios::sync_with_stdio(0);

	cin>>s;

	n = s.size();
	pi[0] = 0;

	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (s[j] != s[i] && j != 0)
			j = pi[j - 1];
		
		if (s[j] != s[i])
			pi[i] = 0;
		else
			pi[i] = j + 1;
	}

	for (int i = 0; i < n; i++)
		h[pi[i]]++;
	for (int i = n - 1; i > 0; i--)
		h[pi[i - 1]] += h[i];
	for (int i = 1; i <= n; i++)
		h[i]++;

	ans.push_back({n, 1});
	int j = pi[n - 1];
	while (j != 0) {
		ans.push_back({j, h[j]});
		j = pi[j - 1];
	}
	reverse(ans.begin(), ans.end());

	cout<<ans.size()<<endl;
	for (pair <int, int> p: ans)
		cout<<p.first<<" "<<p.second<<endl;

	return 0;
}