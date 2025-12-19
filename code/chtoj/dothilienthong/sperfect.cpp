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
#define task "SPERFECT"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int d[N], low[N];
bool out_stack[N];
int id = 0;
vector<int> adj[N];
stack<int> st;
int tplt;
int scc[N];
int indeg[N], outdeg[N];

void dfs(int u) {
    d[u] = low[u] = ++id;
    st.push(u);

    for (auto v : adj[u]) {
        if (!out_stack[v]) {
            if (d[v] == 0) {
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else {
                low[u] = min(low[u], d[v]);
            }
        }
    }
    if (low[u] == d[u]) {
        int v;
        ++tplt;
        // cout << tplt << ": ";
        do {
            v = st.top();
            st.pop();
            out_stack[v] = true;
            scc[v] = tplt;
            // cout << v << ' ';
        } while (u != v);
    }
    // cout << '\n';
}

void logic() {
    int n, m; 
    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        d[i] = low[i] = 0;
        out_stack[i] = false;
        scc[i] = 0;
    }
    while (!st.empty()) st.pop();
    id = 0;
    tplt = 0;

    vector<ii> edges; edges.reserve(m);
    vector<int> rev; rev.reserve(m * 2);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        edges.pb({u, v});
        rev.pb(u);
        rev.pb(v);
    }

    sort(all(rev));
    rev.erase(unique(all(rev)), rev.end());

    for (int u : rev) {
        if (d[u] == 0) dfs(u);
    }
    
    if (tplt == 1) {
        cout << "YES\n";
        return;
    }
    
    for (int i = 1; i <= tplt; ++i) {
        indeg[i] = 0;
        outdeg[i] = 0;
    }

    for (auto e : edges) {
        int u = e.fi;
        int v = e.se;
        if (scc[u] != scc[v]) {
            ++outdeg[scc[u]];
            ++indeg[scc[v]];
        }
    }

    int t1 = 0, t2 = 0;
    for (int i = 1; i <= tplt; ++i) {
        if (indeg[i] == 0) ++t1;
        if (outdeg[i] == 0) ++t2;
    }

    if (t1 == 1 and t2 == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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