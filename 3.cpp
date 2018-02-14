#include <bits/stdc++.h>

using namespace std;

const int N = 212345;

int msb(int x) {
	int ans = 0, curr = 0;
	while (x > 0) {
		if (x%2 == 1)
			ans = curr;
		curr++;
		x /= 2;
	}
	return ans;
}

int n, m;
vector <int> a;
int tree[4*N];

void merge(int i) {
	int lv = n - msb(i);
	if (lv%2 == 1)
		tree[i] = tree[2*i] | tree[2*i + 1];
	else
		tree[i] = tree[2*i] ^ tree[2*i + 1];
}

void build(int i, int tx1, int tx2) {
	if (tx1 > tx2)
		return;
	if (tx1 == tx2)
		tree[i] = a[tx1];
	else {
		int txm = (tx1 + tx2)/2;
		build(2*i, tx1, txm);
		build(2*i + 1, txm + 1, tx2);
		merge(i);
	}
}

void update(int i, int tx1, int tx2, int idx, int val) {
	if (tx1 > tx2 || tx1 > idx || tx2 < idx)
		return;
	if (tx1 == idx && tx2 == idx)
		tree[i] = val;
	else {
		int txm = (tx1 + tx2)/2;
		update(2*i, tx1, txm, idx, val);
		update(2*i + 1, txm + 1, tx2, idx, val);
		merge(i);
	}
}

int main() {
	ios::sync_with_stdio(0);

	cin>>n>>m;
	a.resize((1 << n) + 1);
	for (int i = 1; i <= (1 << n); i++) {
		cin>>a[i];
	}

	build(1, 1, 1 << n);

	while (m--) {
		int p, b;
		cin>>p>>b;
		update(1, 1, 1 << n, p, b);
		cout<<tree[1]<<endl;
	}
	return 0;
}