#include <bits/stdc++.h>

using namespace std;

const int S = 1e6;

int n;
set <int> x;

inline int compliment(int val) {
    return S - val + 1;
}

void solve() {
    int symm = 0;
    vector <int> ans;
    for (int i : x) {
        if (!x.count(compliment(i))) {
            ans.push_back(compliment(i));
        } else {
            symm++;
        }
    }
    for (int i = 1; i <= S; i++) {
        if (!x.count(i) && !x.count(compliment(i)) && symm) {
            ans.push_back(i);
            ans.push_back(compliment(i));
            symm -= 2;
        }
    }

    cout << ans.size() << "\n";
    for (int el : ans) cout << el << " "; cout << "\n";
}

void accept() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        x.insert(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    accept();
    solve();
    return 0;
}