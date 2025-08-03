#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d,x,sizeof(d))
#define task "KSHORT"

using namespace std;
const int N = 1e5 + 5;
const int K = 15;
const int inf = 1e18;

int n, m, k;
vector<ii> adj[N];
int dp[N][K];

priority_queue<iii, vector<iii>, greater<>> pq;

void logic() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            dp[i][j] = inf;

    dp[1][0] = 0;
    pq.push({0, {1, 0}});

    while (!pq.empty()) {
        int du = pq.top().fi;
        int u = pq.top().se.fi;
        int used = pq.top().se.se;
        pq.pop();

        if (du > dp[u][used]) continue;

        for (auto e : adj[u]) {
            int v = e.fi;
            int w = e.se;

            // không làm đường
            if (dp[v][used] > dp[u][used] + w) {
                dp[v][used] = dp[u][used] + w;
                pq.push({dp[v][used], {v, used}});
            }

            // làm đường (nếu còn quyền)
            if (used < k && dp[v][used + 1] > dp[u][used]) {
                dp[v][used + 1] = dp[u][used];
                pq.push({dp[v][used + 1], {v, used + 1}});
            }
        }
    }

    int res = inf;
    for (int i = 0; i <= k; ++i) {
        res = min(res, dp[n][i]);
    }

    if (res == inf) cout << -1;
    else cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();
    return 0;
}