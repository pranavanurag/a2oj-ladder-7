#include <bits/stdc++.h>

using namespace std;

const int N = 212345;

long long n, mod;
vector <long long> a, b;

// fom = (odd component of prime factorization of factorial(i)) % mod
// fp2 = exponent of 2 in fac(i)
vector <long long> fom(N), fp2(N);
void pre() {
    fom[0] = 1, fp2[0] = 0;
    for (int i = 1; i < N; i++) {
        fp2[i] = fp2[i - 1];
        long long cp_i = i;
        while (cp_i % 2 == 0) {
            cp_i /= 2; fp2[i]++;
        }

        fom[i] = (fom[i - 1] * cp_i) % mod;
    }
}

map <int, int> h;
void solve() {
    pre();
    for (int el : a) h[el]++;
    for (int el : b) h[el]++;

    // denominator shall be 2^dup
    int dup = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) dup++;
    }

    // nump2 = exponent of 2 in the numerator
    long long ans = 1;
    int nump2 = 0;
    for (auto entry : h) {
        long long count = entry.second;
        ans = (ans * fom[count]) % mod;
        nump2 += fp2[count];
    }

    nump2 -= dup;
    while (nump2) {
        ans = (ans * 2) % mod;
        nump2--;
    }
    cout << ans << "\n";
}

void accept() {
    cin >> n;
    a.resize(n), b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    cin >> mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    accept();
    solve();

    return 0;
}