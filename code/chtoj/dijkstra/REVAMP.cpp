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
#define task "REVAMP"


using namespace std;
const int N = 1e4 + 9;
const int M = 1e2 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k;
int dp[N][M];
priority_queue<iii, vector<iii>, greater<>> pq;
vector<ii> adj[N];
int res = inf;

void dijk() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            dp[i][j] = inf;
        }
    }
    dp[1][0] = 0;
    pq.push({0, {1, 0}});
    
    while (!pq.empty()) {
        int cost = pq.top().fi;
        int u = pq.top().se.fi;
        int used = pq.top().se.se;
        pq.pop();

        if (cost > dp[u][used]) {
            continue;
        }

        for (auto e : adj[u]) {
            int v = e.fi;
            int w = e.se;

            if (dp[v][used] > dp[u][used] + w) {
                dp[v][used] = dp[u][used] + w;
                pq.push({dp[v][used], {v, used}});
            }

            if (used < k and dp[v][used + 1] > dp[u][used]) {
                dp[v][used + 1] = dp[u][used];
                pq.push({dp[v][used + 1], {v, used + 1}});
            }
        }
    }
}

void logic() {
    cin >> n >> m >> k;
    while (m--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    dijk();

    for (int i = 1; i <= k; ++i) {
        res = min(res, dp[n][i]);
    }
    if (res == inf) cout << -1;
    else {
        cout << res;
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
