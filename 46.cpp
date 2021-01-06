#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve() {
    if (n < m) swap(n, m);
    if (m == 1)  {
        cout << n << "\n";
    } else if (m == 2) {
        n = max(n, 4);
        int rem = n % 4;
        if (rem == 0) cout << n << "\n";
        else cout << ((n / 4) * 4 + ((rem == 1) ? 2 : 4)) << "\n";
    } else {
        cout << (n * m + 1) / 2 << "\n";
    }
}

void accept() {
    cin >> n >> m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    accept();
    solve();

    return 0;
}