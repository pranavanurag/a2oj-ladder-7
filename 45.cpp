#include <bits/stdc++.h>

using namespace std;

const int N = 256;

int n;
vector <int> adj[N];

bool vis[N];
int find_longest_path(int root, int par) {
    memset(vis, 0, sizeof vis);
    stack <pair <int, int>> s;
    int far = root, max_dist = 0;

    s.push({root, 0});
    vis[root] = true;
    vis[par] = true;
    while (!s.empty()) {
        auto curr = s.top();
        s.pop();
        int u = curr.first;
        int dist = curr.second;
        for (int v : adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            s.push({v, dist + 1});

            if (dist + 1 > max_dist) {
                max_dist = dist + 1;
                far = v;
            }
        }
    }

    memset(vis, 0, sizeof vis);
    s.push({far, 0});
    vis[par] = true;
    vis[far] = true;
    int ans = 0;
    while (!s.empty()) {
        auto curr = s.top();
        s.pop();
        int u = curr.first;
        int dist = curr.second;
        for (int v : adj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            s.push({v, dist + 1});
            ans = max(ans, dist + 1);
        }
    }

    return ans;
}

int ans = 0;
void solve(int u, int par) {
    for (int v : adj[u]) {
        if (v == par) continue;
        int curr1 = find_longest_path(v, u);
        int curr2 = find_longest_path(u, v);
        ans = max(ans, curr1 * curr2);

        solve(v, u);
    }
}

void solve() {
    solve(1, -1);
    cout << ans << "\n";
}

void accept() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
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