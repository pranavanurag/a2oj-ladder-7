#include <bits/stdc++.h>

using namespace std;

int n, m;
set <pair <int, int> > s;

int temp_score(vector <pair <int, int> > &v) {
	int ans = 0;
	for (auto p: v)
		if (s.find(p) != s.end())
			ans++;		
	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for (int i = 2; i <= n - 1; i++) {
		s.insert({1, i});
		s.insert({n, i});
		s.insert({i, 1});
		s.insert({i, n});
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin>>a>>b;
		s.erase({a, 1});
		s.erase({a, n});
		s.erase({1, b});
		s.erase({n, b});
	}

	int ans = 0;
	for (int i = 2; i <= (n + 1)/2; i++) {
		vector <pair <int, int> > v1 = {{1, i}, {n, n - i + 1}, {i, n}, {n - i + 1, 1}};
		if (n%2 == 1 && i == (n + 1)/2) {
			ans += temp_score(v1) > 0;
			continue;
		}
		vector <pair <int, int> > v2 = {{n, i}, {1, n - i + 1}, {i, 1}, {n - i + 1, n}};
		ans += max(temp_score(v1), temp_score(v2));
	}

	cout<<ans<<endl;
	return 0;
}