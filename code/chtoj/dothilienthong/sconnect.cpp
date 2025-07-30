#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
#define task "SCONNECT"


const int N = 1e6 + 9;

int n, m;
vector<int> adj[N];
int d[N], low[N], id;
bool in_stack[N];
stack<int> st;

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
        int v;
        do {
            v = st.top(); st.pop();
            in_stack[v] = false;
            cout << v << " ";
        } while (u != v);
        cout << "\n";
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!d[i]) dfs(i);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();

    // execute;
    return 0;
}