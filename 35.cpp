#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

string tmp;
int n, a[N];

int main() {
	ios::sync_with_stdio(0);

	cin>>tmp;
	n = tmp.size();
	for (int i = 1; i <= n; i++)
		a[i] = tmp[i - 1] == 'F';

	int i = 1;
	while (a[i] == 1 && i <= n)
		i++;
	int dest = i, curr = 0;
	for (i; i <= n; i++) {
		if (!a[i])
			continue;

		curr = max(curr + 1, i - dest);
		dest++;
	}

	cout<<curr<<endl;

	return 0;
}