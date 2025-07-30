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
#define task "CNODE"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int low[N], d[N];
int cnt;
int vung;
vector<ii> adj[N];
stack<int> s;
set<int> khop;
vector<ii> cau;
int tplt;
int scc[N];
int n, m;
ii e[N];

void dfs(int u, int id) {
    int vung = 0;
    low[u] = d[u] = ++cnt;
    s.push(u);
    for (auto e : adj[u]) {
        int v = e.fi;
        int nid = e.se;
        if (id != nid) {
            if(d[v] != 0) {
                low[u] = min(low[u], d[v]);
            }
            else {
                dfs(v, nid);
                low[u] = min(low[u], low[v]);
                if (id != -1 and low[v] >= d[u]) {
                    khop.insert(u);
                }
                ++vung;
            }
        }
    }
    if (id == -1 and vung > 1) {
        khop.insert(u);
    }
    if (low[u] == d[u]) {
        tplt++;
        int v;
        do {
            v = s.top();
            scc[v] = tplt;
            s.pop();
        } while(u != v);
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb({v, i});
        adj[v].pb({u, i});
        e[i] = {u, v};
    }
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            dfs(i, -1);
        }
    }

    sort (cau.begin(), cau.end());
    cout << khop.size() << endl;
    for (auto x : khop) {
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
