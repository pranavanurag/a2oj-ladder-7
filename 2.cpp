#include <bits/stdc++.h>

using namespace std;

long long cost[5], cnt[5];
long long n;
vector <long long> p;
vector <pair <long long, long long> > h;

void calc(long long &curr) {
	for (long long i = 0; i < 5; i++) {
		if (curr >= h[i].first) {
			long long get = curr/h[i].first;
			curr -= get*h[i].first;
			cnt[h[i].second] += get;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);

	memset(cnt, 0, sizeof cnt);

	cin>>n;
	p.resize(n);
	for (long long i = 0; i < n; i++)
		cin>>p[i];
	for (long long i = 0; i < 5; i++) {
		cin>>cost[i];
		h.push_back({cost[i], i});
	}
	sort(h.rbegin(), h.rend());

	long long curr = 0;
	for (long long i = 0; i < n; i++) {
		curr += p[i];
		calc(curr);
	}

	for (long long i = 0; i < 5; i++)
		cout<<cnt[i]<<" ";
	cout<<endl;
	cout<<curr<<endl;

	return 0;
}