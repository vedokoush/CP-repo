#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
#define task "CSPATH"

using namespace std;
const int N = 2e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

vector<ii> adj[N];
int dist[N];
int ways[N];
priority_queue<ii, vector<ii>, greater<>> pq;

void dijk(int n, int start) {
    while (!pq.empty()) {
        pq.pop();
    }
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
        ways[i] = 0;
    }
    dist[start] = 0;
    ways[start] = 1;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int cost = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto e : adj[u]) {
            int v = e.fi;
            int c = e.se;
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + c) {
                ways[v] = (ways[v] + ways[u]) % mod;
            }
        }
    }
}

void logic() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    dijk(n, 1);

    for (int i = 1; i <= n; ++i) {
        if (dist[i] == inf) {
            cout << -1 << ' ' << 0 << '\n';
        }
        else {
            cout << dist[i] << ' ' << ways[i] << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int t; cin >> t;
    while (t--) {
        logic();
    }

    return 0;
}