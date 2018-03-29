#include <bits/stdc++.h>

using namespace std;

const long long N = 123456;

long long a[2][N], b[2][N];
string s;

int main() {
	ios::sync_with_stdio(0);

	cin>>s;
	long long od = 0, ev = 0, n = s.size();
	for (long long i = 0; i < n; i++) {

		a[0][i] = a[0][i - 1], a[1][i] = a[1][i - 1];
		b[0][i] = b[0][i - 1], b[1][i] = b[1][i - 1];

		if (s[i] == 'a') {
			a[i%2][i]++;

			od += a[i%2][i];
			ev += a[!(i%2)][i];
		}
		else {
			b[i%2][i]++;

			od += b[i%2][i];
			ev += b[!(i%2)][i];
		}
	}

	cout<<ev<<" "<<od<<endl;
	return 0;
}