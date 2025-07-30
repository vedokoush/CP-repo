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
#define task "FLOWERS"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int id;
int m;
int d[N];
int low[N];
bool out_stack[N];
int n;
stack<int> st;
vector<int> adj[N];
int tplt;
vector<int> ssc[N];
vector<ii> edge;
int par[N];
map<int, int> cdag;
int smin = inf;

void dfs(int u) {
    d[u] = low[u] = ++id;
    st.push(u);
    for (auto v : adj[u]) {
        if (out_stack[v] == false) {
            if (d[v] != 0) {
                low[u] = min(low[u], d[v]);
            }
            else {
                dfs(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] == d[u]) {
        int v; 
        ++tplt;
        // cout << tplt << ": ";
        do {
            v = st.top();
            out_stack[v] = true;
            ssc[tplt].pb(v);
            par[v] = tplt;
            // cout << v << ' ';
            st.pop();
        }while (v != u);
        // cout << endl;
    }
}

void logic() {
    cin >> n;
    // for (int i = 1; i <= m; ++i) {
    //     int u, v; cin >> u >> v;
    //     adj[u].pb(v);
    // }
    int u, v;
    while (cin >> u >> v) {
        adj[u].pb(v);
        edge.pb({u, v});
    }
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            dfs(i);
        }
    }
    // cout << '\n';
    // cout << ssc[1].size();
    for (auto e : edge) {
        int u = e.fi;
        int v = e.se;
        if (par[u] != par[v]) {
            ++cdag[par[u]];
        }
    }

    int mt = 0;
    for (int i = 1; i <= tplt; ++i) {
        if (cdag[i] == 0 and (int)ssc[i].size() < smin) {
            mt = i;
            smin = (int)ssc[i].size();
        }
    }
    cout << smin << '\n';
    for (auto x : ssc[mt]) {
        cout << x << ' ';
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
