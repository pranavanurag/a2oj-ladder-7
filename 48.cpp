#include <bits/stdc++.h>

using namespace std;

int n, h;

map <int, map<int, long long> > mem;

long long solve_exact_height(int x, int y) {
    if (!mem[x].count(y)) {
        long long curr = 0;
        if (x == 0 && y == 0) curr = 1;
        else if (x == 1 && y == 1) curr = 1;
        else if (x < y) curr = 0;
        else if (y == 0) curr = 0;
        else {
            for (int hinge = 1; hinge <= x; hinge++) {
                int lc = hinge - 1, rc = x - hinge;
                long long left_guarantees = solve_exact_height(lc, y - 1);
                for (int rh = 0; rh <= y - 1; rh++) curr += left_guarantees * solve_exact_height(rc, rh);

                long long right_guarantees = solve_exact_height(rc, y - 1);
                for (int lh = 0; lh <= y - 2; lh++) curr += right_guarantees * solve_exact_height(lc, lh);
            }
        }
        mem[x][y] = curr;
    }
    return mem[x][y];
}

long long solve_at_least_height(int x, int y) {
    long long curr = 0;
    for (int ht = y; ht <= x; ht++) {
        curr += solve_exact_height(x, ht);
    }
    return curr;
}

void solve() {
    cout << solve_at_least_height(n, h) << "\n";
}

void accept() {
    cin >> n >> h;
}

int main() {
    accept();
    solve();
    return 0;
}