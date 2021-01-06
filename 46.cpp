#include <bits/stdc++.h>

using namespace std;

int n, m;

void solve() {
    if (n < m) swap(n, m);
    if (m == 1)  {
        cout << n << "\n";
    } else if (m == 2) {
        if (n < 4) {
            cout << 4 << "\n";
        } else {
            int rem = n % 4;
            if (rem == 0) {
                cout << n << "\n";
            }
            else {
                int whole = (n / 4) * 4;
                if (rem == 1) {
                    cout << whole + 2 << "\n";
                } else {
                    cout << whole + 4 << "\n";
                }
            }
        }
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