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
#define task "RMOVE"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist1[N], dist2[N];
int n, m;
queue<int> q1, q2;
vector<int> adj[N], adjn[N];
int trace1[N], trace2[N];

void bfs1(int start) {
    for (int i = 1; i <= m; ++i) {
        dist1[i] = inf;
        trace1[i] = -1;
    }
    dist1[start] = 0;
    trace1[start] = 0;
    q1.push(start);
    while (!q1.empty()) {
        int u = q1.front();
        q1.pop();
        for (auto v : adj[u]) {
            if (dist1[v] > dist1[u] + 1) {
                dist1[v] = dist1[u] + 1;
                trace1[v] = u;
                q1.push(v);
            }
        }
    }
}

void bfs2(int start) {
    for (int i = 1; i <= m; ++i) {
        dist2[i] = inf;
        trace2[i] = -1;
    }
    dist2[start] = 0;
    trace2[start] = 0;
    q2.push(start);
    while (!q2.empty()) {
        int u = q2.front();
        q2.pop();
        for (auto v : adjn[u]) {
            if (dist2[v] > dist2[u] + 1) {
                dist2[v] = dist2[u] + 1;
                trace2[v] = u;
                q2.push(v);
            }
        }
    }
}

void truyvet1(int x) {
    vector<int> path;
    while (x != 0) {
        path.pb(x);
        x = trace1[x];
    }
    reverse(all(path));
    for (auto x : path) {
        cout << x << ' ';
    }
}

void truyvet2(int x) {
    vector<int> path;
    while (x != 0) {
        path.pb(x);
        x = trace2[x];
    }
    reverse(all(path));
    for (auto x : path) {
        cout << x << ' ';
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adjn[u].pb(v);
    }
    bfs1(1);
    bfs2(n);
    for (int i = 1; i <= n; ++i) {
        if (dist1[i] == dist2[i] and dist1[i] != inf) {
            cout << dist1[i] << '\n';
            truyvet1(i);
            cout << '\n';
            truyvet2(i);
            return;
        }
    }
    cout << -1;
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
    
    /*
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
    */

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/
