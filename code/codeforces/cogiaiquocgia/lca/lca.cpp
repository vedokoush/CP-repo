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
#define task "LCA"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int p[N][31];
int h[N];
vector<int> adj[N];

void dfs(int u, int par) {
    for (auto v : adj[u]) {
        if (v != par) {
            h[v] = h[u] + 1;
            p[v][0] = u;
            dfs(v, u);
        }
    }
}

void init() {
    for (int j = 1; j <= 30; ++j) {
        for (int i = 1; i <= n; ++i) {
            p[i][j] = p[p[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (h[u] < h[v]) {
        swap(u, v);
    }
    int x = h[u] - h[v];
    for (int i = log2(x); i >= 0; i--) {
        if (x >= (1 << i)) {
            u = p[u][i];
            x -= (1 << i);
        }
    }

    if (u == v) {
        return u;
    }

    for (int x = log2(h[u]); x >= 0; x--) {
        if (p[u][x] != p[v][x]) {
            u = p[u][x];
            v = p[v][x];
        }
    }
    return p[u][0];
} 

void logic() {
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1, -1);
    init();
    int k; cin >> k;
    while (k--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << '\n';
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
