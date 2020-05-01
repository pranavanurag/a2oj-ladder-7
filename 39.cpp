#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> v;
stack <int> s;

vector <int> ttl, stree;
void update(int i, int tx1, int tx2, int x, int val) {
    if (tx1 > tx2 || tx1 > x || tx2 < x) {
        return;
    } else if (tx1 == tx2 && tx1 == x) {
        stree[i] = val;
    } else {
        int txm = (tx1 + tx2) / 2;
        update(2 * i, tx1, txm, x, val);
        update(2 * i + 1, txm + 1, tx2, x, val);
        stree[i] = max(stree[2 * i], stree[2 * i + 1]);
    }
}

void update(int x, int val) {
    update(1, 1, n, x, val);
}

int query(int i, int tx1, int tx2, int x1, int x2) {
    if (tx1 > tx2 || tx1 > x2 || tx2 < x1 || x1 > x2) {
        return 0;
    } else if (tx1 >= x1 && tx2 <= x2) {
        return stree[i];
    } else {
        int txm = (tx1 + tx2) / 2;
        int left = query(2 * i, tx1, txm, x1, x2);
        int right = query(2 * i + 1, txm + 1, tx2, x1, x2);
        return max(left, right);
    }
}

int query(int x) {
    return query(1, 1, n, 1, x);
}

void solve() {
    stree.resize(4 * (n + 1), 0);
    ttl.resize(n + 1);

    int killer = n;
    while (killer > 0) {
        int curr_time = 0;
        while (true) {
            if (s.empty()) {
                s.push(killer);
                break;
            }
            int victim = s.top();
            if (v[killer] < v[victim]) {
                s.push(killer);
                break;
            }
            ttl[victim] = max(curr_time + 1, query(victim - 1) + 1);
            update(victim, ttl[victim]);
            s.pop();
            curr_time = ttl[victim];
        }
        killer--;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ttl[i]);
    }
    cout << ans << endl;
}

void accept() {
    cin >> n;
    v.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
}


int main() {
    ios::sync_with_stdio(false);
    accept();
    solve();
    return 0;
}
