#include <bits/stdc++.h>

using namespace std;

const int N = 5123;

int n, m;
vector <vector <int> > a, cont;

void sort_column(int col) {
	vector <int> tmp(m + 1);
	for (int i = 0; i < n; i++)
		tmp[cont[i][col]]++;

	int curr = m, ridx = 0;
	while (curr >= 0) {
		while (tmp[curr] > 0)
			tmp[curr]--, cont[ridx++][col] = curr;
		curr--;
	}
}

void show(vector <vector <int> > x) {
	int n = x.size(), m = x[0].size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout<<x[i][j]<<" ";
		cout<<endl;
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m;
	a.resize(n);
	cont.resize(n);
	for (int i = 0; i < n; i++) {
		string tmp;
		cin>>tmp;

		a[i].resize(m);
		cont[i].resize(m);
		for (int j = 0; j < m; j++)
			a[i][j] = tmp[j] == '1';
	}

	for (int i = 0; i < n; i++) {
		cont[i][0] = a[i][0];
		for (int j = 1; j < m; j++)
			if (a[i][j] == 1)
				cont[i][j] = cont[i][j - 1] + 1;
			else
				cont[i][j] = 0;
	}


	for (int col = 0; col < m; col++)
		sort_column(col);

	int ans = 0;
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			ans = max(ans, (i + 1)*cont[i][j]);

	cout<<ans<<endl;

	return 0;
}