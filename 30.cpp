#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

int n, a[N], smin[N];

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	smin[n] = a[n];
	for (int i = n - 1; i >= 1; i--)
		if (a[i] < smin[i + 1])
			smin[i] = a[i];
		else
			smin[i] = smin[i + 1];

	for (int i = 1; i <= n; i++) {
		int low = i, high = n, mid;
		while (low < high) {
			mid = (low + high + 1)/2;
			if (smin[mid] < a[i])
				low = mid;
			else
				high = mid - 1;
		}
		cout<<low - i - 1<<" ";
	}
	cout<<endl;
	return 0;
}