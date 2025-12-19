#include <bits/stdc++.h>
using namespace std;
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
#define task ""

const int N = 1e6 + 9;

int n, m;
vector<int> adj[N];
int d[N], low[N], id;
bool in_stack[N];
stack<int> st;
int tplt;
int ssc[N];
vector<ii> edge;
int ans;

void dfs(int u) {
    d[u] = low[u] = ++id;
    st.push(u);
    in_stack[u] = true;

    for (auto v : adj[u]) {
        if (!d[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (in_stack[v]) {
            low[u] = min(low[u], d[v]);
        }
    }

    if (low[u] == d[u]) {
        ++tplt;
        int v;
        do {
            v = st.top(); st.pop();
            in_stack[v] = false;
            ssc[v] = tplt;
        } while (u != v);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        edge.pb({u, v});
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) dfs(i);
    }
    for (auto e : edge) {
        int u = e.fi;
        int v = e.se;
        if (ssc[u] != ssc[v]) {
            ++ans;
        }
    }
    cout << ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();
    return 0;
}