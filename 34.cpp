#include <bits/stdc++.h>

using namespace std;

#define INF INT_MAX

const long long N = 123456;

struct ccompare {
	bool operator() (const pair <long long, long long> &lhs, const pair <long long, long long> &rhs) {
		return lhs.second > rhs.second;
	}
};

long long n, m;
vector <pair <long long, long long> > adj[N];
vector <long long> wait[N];
unordered_map <long long, bool> hwait[N];
unordered_map <long long, long long> vac[N];

void pre() {
	for (long long u = 1; u <= n; u++) {
		long long sz = wait[u].size(), i;
		for (i = 0; i < sz; i++) {
			long long curr_vac = wait[u][i] + 1, j;
			for (j = i + 1; j < sz; j++) {
				if (wait[u][j] != wait[u][j - 1] + 1)
					break;
				curr_vac++;
			}

			for (long long k = i; k < j; k++)
				vac[u][wait[u][k]] = curr_vac;

			i = j - 1;
		}
	}
}

long long dist[N];
bool vis[N];
priority_queue <pair <long long, long long>, vector <pair <long long, long long> >, ccompare> pq;

inline long long getvacancy(long long u, long long curr_time) {
	if (hwait[u][curr_time])
		return vac[u][curr_time];
	return curr_time;
}

void f() {
	while (!pq.empty()) {
		long long u = pq.top().first;
		long long curr_time = pq.top().second;
		pq.pop();
		if (!vis[u]) {
			vis[u] = 1;
			for (pair <long long, long long> p: adj[u]) {
				long long v = p.first, d = p.second;
				long long dest_time = curr_time + d;
				if (v != n)
					dest_time = getvacancy(v, dest_time);

				if (dist[v] > dest_time) {
					dist[v] = dest_time;
					pq.push({v, dist[v]});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for (long long i = 0; i < m; i++) {
		long long u, v, d;
		cin>>u>>v>>d;
		adj[u].push_back({v, d});
		adj[v].push_back({u, d});
	}

	for (long long i = 1; i <= n; i++) {
		long long tmp;
		cin>>tmp;
		wait[i].resize(tmp);
		for (long long j = 0; j < tmp; j++) {
			cin>>wait[i][j];
			hwait[i][wait[i][j]] = 1;
		}
	}

	pre();

	for (long long i = 1; i <= n; i++)
		dist[i] = INF;
	dist[1] = getvacancy(1, 0);
	memset(vis, 0, sizeof vis);
	for (long long i = 1; i <= n; i++)
		pq.push({i, dist[i]});

	f();
	if (dist[n] == INF)
		cout<<-1<<endl;
	else
		cout<<dist[n]<<endl;

	return 0;
}