    #include <bits/stdc++.h>
     
    using namespace std;
     
    const double EPS = 1e-10;
    const double INF = 1e10;
     
    double a, b, m, vx, vy, vz;
     
    double travel(double curr, double vel, double time) {
        return curr + vel * time;
    }
     
    pair <double, double> solve(double cx, double cz, double cvx, double cvz, double tr) {
        // cout << "at (" << cx << ", " << cz << "), speeds (" << cvx << ", " << cvz << "), time remaining = " << tr << "\n";
        double sidetime = (cvx == 0)? INF : (cvx > 0) ? abs((a - cx) / cvx) : abs(cx / cvx);
        double verticaltime = (cvz == 0) ? INF : (cvz > 0) ? abs((b - cz) / cvz) : abs(cz / cvz);
        if (sidetime >= tr && verticaltime >= tr) {
            return {travel(cx, cvx, tr), travel(cz, cvz, tr)};
        }
     
        if (sidetime < verticaltime) {
            return solve(travel(cx, cvx, sidetime), travel(cz, cvz, sidetime), -cvx, cvz, tr - sidetime);
        } else if (verticaltime < sidetime) {
            return solve(travel(cx, cvx, verticaltime), travel(cz, cvz, verticaltime), cvx, -cvz, tr - verticaltime);
        } else {
            return solve(travel(cx, cvx, sidetime), travel(cz, cvz, verticaltime), -cvx, -cvz, tr - sidetime);
        }
    }
     
    void solve() {
        auto ans = solve(a / 2, 0, vx, vz, abs(m / vy));
        if (ans.first < EPS) ans.first = 0;
        if (ans.second < EPS) ans.second = 0;
        cout << ans.first << " " << ans.second << "\n";
    }
     
    void accept() {
        cin >> a >> b >> m;
        cin >> vx >> vy >> vz;
    }
     
    int main() {
        cout << setprecision(7);
        accept();
        solve();
        return 0;
    }