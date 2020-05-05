#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <int> a, d, x;

int try_defeat_all() {
    vector <int> cpx = x;
    sort(cpx.begin(), cpx.end());
    int enemy_count = a.size() + d.size();
    int defeated = 0;
    for (int def : d) {
        auto it = lower_bound(cpx.begin(), cpx.end(), def + 1);
        if (it != cpx.end()) {
            defeated++;
            cpx.erase(it);
        }
    }
    int damage = 0;
    for (int atk : a) {
        auto it = lower_bound(cpx.begin(), cpx.end(), atk);
        if (it != cpx.end()) {
            defeated++;
            damage += *it - atk;
            cpx.erase(it);
        }
    };
    if (defeated == enemy_count) for (int el : cpx) damage += el;
    return damage;
}

int take_atk() {
    sort(x.begin(), x.end());
    reverse(x.begin(), x.end());
    sort(a.begin(), a.end());
    int ans = 0, defeated = 0;
    for (int i = 0; i < x.size() && i < a.size(); i++) {
        if (x[i] >= a[i]) {
            ans += x[i] - a[i];
            defeated++;
        }
    }
    return ans;
}

void solve() {
    cout << max(try_defeat_all(), take_atk()) << endl;
}

void accept() {
    cin >> n >> m;
    while (n--) {
        string type;
        int str;
        cin >> type >> str;
        if (type == "ATK") {
            a.push_back(str);
        } else {
            d.push_back(str);
        }
    }
    x.resize(m);
    for (int i = 0; i < m; i++) cin >> x[i];
}

int main() {
    ios::sync_with_stdio(false);
    accept();
    solve();
    return 0;
}
