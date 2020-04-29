#include <iostream>
#include <vector>

using namespace std;

#define INF ((int)(1e9))

int n, m, k;
vector <vector <pair <int, int>>> adj;
vector <int> c, cnt;

// effective color (in case type distribution is 'good')
vector <int> eff;
vector <bool> vis;
// travels only free edges, returns number of vertices of given color found
int dfs(int u, int color) {
    eff[u] = color;
    int ans =(c[u] == color);
    for (auto edge : adj[u]) {
        int v = edge.first, cost = edge.second;
        if (cost > 0 || vis[v] == true) {
            continue;
        }
        vis[v] = true;
        ans += dfs(v, color);
    }
    return ans;
}

bool check_connectivity(int color) {
    vis.clear();
    vis.resize(n + 1);
    for (int u = 1; u <= n; u++) {
        if (c[u] == color) {
            vis[u] = true;
            return dfs(u, color) == cnt[color];
        }
    }
    return false;
}

vector <vector <int>> d;
void print_d() {
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (d[i][j] != INF) {
                cout << d[i][j] << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
}

void calc() {
    d.resize(k + 1);
    for (int i = 1; i <= k; i++) d[i].resize(k + 1, INF);
    
    for (int u = 1; u <= n; u++) {
        d[c[u]][c[u]] = 0;
        for (auto edge : adj[u]) {
            int v = edge.first, cost = edge.second;
            if (eff[u] != eff[v]) {
                d[eff[u]][eff[v]] = min(d[eff[u]][eff[v]], cost);
                d[eff[v]][eff[u]] = min(d[eff[v]][eff[u]], cost);
            } else if (c[u] != c[v]) {
                d[c[u]][c[v]] = min(d[c[u]][c[v]], 0);
                d[c[v]][c[u]] = min(d[c[v]][c[u]], 0);
            }
        }
    }

    for (int i3 = 1; i3 <= k; i3++) {
        for (int i1 = 1; i1 <= k; i1++) {
            for (int i2 = 1; i2 <= k; i2++) {
                d[i1][i2] = min(d[i1][i2], d[i1][i3] + d[i3][i2]);
            }
        }
    }
}

void solve() {
    eff = c;    
    for (int color = 1; color <= k; color++) {
        if (!check_connectivity(color)) {
            cout << "No" << endl;
            return;
        }
    }
    // type distribution is 'good'
    cout << "Yes" << endl;
    calc();
    print_d();
}

void accept() {
    cin >> n >> m >> k;

    c.resize(n + 1);
    cnt.resize(k + 1);
    int c_idx = 1;
    for (int i = 1; i <= k; i++) {
        cin >> cnt[i];
        int tmp = cnt[i];
        while (tmp--) {
            c[c_idx++] = i;
        }
    }

    adj.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }
}

int main() {
	ios::sync_with_stdio(0);
    accept();
    solve();
    return 0;
}
