#include <bits/stdc++.h>

using namespace std;

vector <int> all_factors(int x) {
	vector <int> ans;
	for (int i = 1; i*i <= x; i++) {
		if (x%i == 0) {
			ans.push_back(i);
			if (i*i != x)
				ans.push_back(x/i);
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}

bool check(string x, int f) {
	int n = x.size();
	for (int i = 0; i < n; i++)
		if (x[i] != x[i%f])
			return 0;
	return 1;
}

int get_sf(string x, vector <int> v) {
	for (int f: v)
		if (check(x, f))
			return f;
	return x.size();
}

vector <int> f(int n, int f) {
	vector <int> ans = all_factors(n/f);
	for (int i = 0; i < ans.size(); i++)
		ans[i] *= f;
	return ans;
}

vector <int> intersection(vector <int> x, vector <int> y) {
	vector <int> ans;
	for (int el: x)
		if (binary_search(y.begin(), y.end(), el))
			ans.push_back(el);
	return ans;
}

string x, y;
int n, m;

int main() {
	ios::sync_with_stdio(0);

	cin>>x>>y;
	n = x.size(), m = y.size();

	vector <int> u = all_factors(n), v = all_factors(m);
	int a = get_sf(x, u), b = get_sf(y, v);
	vector <int> ans = intersection(f(n, a), f(m, b));

	if (ans.size() == 0) {
		cout<<0<<endl;
		return 0;
	}

	int check_for = ans[0];
	if (x.substr(0, check_for) == y.substr(0, check_for))
		cout<<ans.size()<<endl;
	else
		cout<<0<<endl;
	return 0;
}