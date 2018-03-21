#include <bits/stdc++.h>

using namespace std;

int x, y, z, xx, yy, zz;
int a[7];

int main() {
	ios::sync_with_stdio(0);

	cin>>x>>y>>z;
	cin>>xx>>yy>>zz;
	for (int i = 1; i <= 6; i++)
		cin>>a[i];

	int ans = 0;
	if (x < 0)
		ans += a[5];
	else if (x > xx)
		ans += a[6];

	if (y < 0)
		ans += a[1];
	else if (y > yy)
		ans += a[2];

	if (z < 0)
		ans += a[3];
	else if (z > zz)
		ans += a[4];

	cout<<ans<<endl;

	return 0;
}