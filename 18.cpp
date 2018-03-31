#include <bits/stdc++.h>

using namespace std;

struct node {
	char c;
	map <char, node*> m;
};

void add(node* curr, string word, int idx) {
	if (curr == NULL || idx == word.size())
		return;

	char x = word[idx];
	if (!curr->m.count(x)) {
		node* next = new node;
		curr->m[x] = next;
		next->c = x;
	}

	add(curr->m[x], word, idx + 1);
}

string s;
bool b[26];
int k, n;

int rec(node* curr, int k_curr) {
	if (curr == NULL)
		return 0;

	int ans = 0;
	k_curr += b[curr->c - 'a'];

	if (k_curr <= k)
		ans++;

	for (pair <char, node*> p: curr->m)
		ans += rec(p.second, k_curr);

	return ans;
}

int main() {
	ios::sync_with_stdio(0);

	cin>>s;
	n = s.size();
	string tmp;
	cin>>tmp;
	for (int i = 0; i < 26; i++)
		b[i] = tmp[i] - '1';
	cin>>k;

	node* th = new node;
	th->c = ' ';

	for (int i = 0; i < n; i++)
		add(th, s, i);

	int ans = 0;
	for (pair <char, node*> p: th->m)
		ans += rec(p.second, 0);

	cout<<ans<<endl;
	return 0;
}