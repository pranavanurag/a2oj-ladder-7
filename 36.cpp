#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, li[N];

void upd(int f, int i, int y, int &ans) {
	if (i - li[f] > y)
		ans++;
	li[f] = i;
}

int main() {
	ios::sync_with_stdio(0);

	memset(li, 0, sizeof li);

	cin>>n;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin>>x>>y;
		int ans = 0;
		for (int f = 1; f*f <= x; f++) {
			if (x%f == 0) {
				upd(f, i, y, ans);

				if (f*f != x)
					upd(x/f, i, y, ans);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}