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
// dont copy my flow dude
#define task "CAPTION"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dist[N];
priority_queue<ii, vector<ii>, greater<>> pq;
int n, m, s, t;
vector<ii> adj[N];
int bom[N];

void dijk(int start) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
    }
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        int cost = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (cost != dist[u]) {
            continue;
        }

        for (auto e : adj[u]) {
            int v = e.fi;
            int c = e.se;
            if (dist[v] > dist[u] + c and (bom[v] == 0 or dist[u] + c < bom[v])) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

void logic() {
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> bom[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijk(s);
    if (dist[t] == inf) {
        cout << -1;
    }
    else {
        cout << dist[t];
    }
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/
