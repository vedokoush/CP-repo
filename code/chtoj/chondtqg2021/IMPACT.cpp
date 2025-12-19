#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define task "CHANGE"

using namespace std;

const int N = 1e3 + 9;
const int inf = 1e18;

int n, m;
vector<int> adj[N];
int vis[N];
int ans = inf;


void ql(int i, int cnt) {
    if (i > n) {
        for (int j = 1; j <= n; ++j)
            if (!vis[j]) return;
        ans = min(ans, cnt);
    }
    else {
        vis[i] ^= 1;
        for (auto v : adj[i]) {
            vis[v] ^= 1;
        }
        ql(i + 1, cnt + 1);
        vis[i] ^= 1;
        for (auto v : adj[i]) {
            vis[v] ^= 1;
        }
        ql(i + 1, cnt);
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    ql(1, 0);
    cout << ans;
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
    return 0;
}