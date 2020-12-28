#include <bits/stdc++.h>
    
using namespace std;
    
double a, b;
    
int main() {
    ios::sync_with_stdio(false);
    cout << setprecision(10);
    int t; cin >> t;
    while (t--) {
        cin >> a >> b;
        if (a == 0 && b == 0) cout << 1 << endl;
        else if (a < 4 * b) cout << (a + 8 * b) / (16 * b) << endl;
        else cout << (1 - (b / a)) << endl;
    }
    return 0;
}