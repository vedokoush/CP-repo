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
#define task "BFS3"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
int st, en;
vector<int> res;
vector<pair<int, int>> adj[N];
int trace[N], edge[N];
bool check[N];
queue<int> q;

void bfs(int start) {
    q.push(start);
    check[start] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, id] : adj[u]) {
            if (!check[v]) {
                check[v] = true;
                trace[v] = u;
                edge[v] = id;
                q.push(v);
            }
        }
    }
}

void logic() {
    cin >> n >> m >> st >> en;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb({v, i});
    }
    for (int i = 1; i <= m; ++i) {
        sort(all(adj[i]));
    }
    bfs(st);
    int u = en;
    while (u > 0) {
        res.pb(edge[u]);
        u = trace[u];
    }
    reverse(all(res));
    for (int i = 1; i < (int)res.size(); ++i) {
        cout << res[i] << ' ';
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

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/
