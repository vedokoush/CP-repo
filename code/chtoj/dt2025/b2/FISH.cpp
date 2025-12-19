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
#define task "fish"
// dont copy my flow dude

using namespace std;

cofnst int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n;
int a[N];
double dp[N]; 
vector<pair<int, ii>> adj[N]; 
void dfs(int u, int p) {
    if (a[u] != -1) {
        dp[u] = (double)a[u];
      
}
    for (auto x : adj[u]) {
        int v = x.fi;
        int edge = x.se.;
        if (v == p) continue;

        int x = edge.fi;
        int k = edge.se;

        dfs(v, u);

        double val;
        if (k == 0) {
            val = dp[v];
        } else {
            val = sqrt(dp[v]);
        }

        val = val * 100.0 / x;
        dp[u] = max(dp[u], val);
    }
}

void logic() {
    cin >> n;
    int m = n - 1;
    for (int i = 1; i <= m; ++i) {
        int u, v, x, k;
        cin >> u >> v >> x >> k;
        adj[u].pb({v, {x, k}});
        adj[v].pb({u, {x, k}});
    }

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    dfs(1, -1);

    cout << fixed << setprecision(4) << dp[1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();

    // execute;
    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/