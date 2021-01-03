#include <bits/stdc++.h>
    
using namespace std;
    
const int INF = 1e9;
const int N = 123;
    
int dp[N][N][N], pi[N];
string s1, s2, vir;
    
void compute_pi() {
    pi[0] = 0;
    for (int i = 1; i < vir.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && vir[i] != vir[j])
            j = pi[j - 1];
        if (vir[i] == vir[j])
            j++;
        pi[i] = j;
    }
}
    
void pre() {
    memset(dp, -1, sizeof dp);
    compute_pi();
}
    
int use_pi(char c, int x) {
    while (x > 0 && c != vir[x])
        x = pi[x - 1];
    if (vir[x] == c) x++;
    return x;
}
    
int rec(int i, int j, int k) {
    if (k >= vir.size()) {
        return -INF;
    } else if (i >= s1.size() || j >= s2.size()) {
        return 0;
    } else if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    
    int ans = 0;
    if (s1[i] == s2[j])
        ans = 1 + rec(i + 1, j + 1, use_pi(s1[i], k));
    ans = max(ans, max(rec(i, j + 1, k), rec(i + 1, j, k)));
    dp[i][j][k] = ans;
    return ans;
}
    
vector <char> ans;
void construct(int i, int j, int k) {
    if (i == s1.size() || j == s2.size() || k == vir.size()) return;
    if (s1[i] == s2[j]) {
        int x = use_pi(s1[i], k);
        if (rec(i, j, k) == 1 + rec(i + 1, j + 1, x)) {
            ans.push_back(s1[i]);
            construct(i + 1, j + 1, x);
            return;
        }
    }
    if (rec(i, j, k) == rec(i + 1, j, k)) construct(i + 1, j, k);
    else construct(i, j + 1, k);
}
    
void solve() {
    pre();
    if (rec(0, 0, 0) > 0) {
        construct(0, 0, 0);
        for (char c : ans) cout << c; cout << "\n";
    } else {
        cout << 0 << "\n";
    }
}
    
void accept() {
    cin >> s1 >> s2 >> vir;
}
    
int main() {
    accept();
    solve();
    return 0;
}