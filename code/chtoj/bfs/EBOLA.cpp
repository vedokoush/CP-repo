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
#define task ""


using namespace std;
const int N = 2 * 1e5 + 5;
const int M = 1e5 + 5;
const int inf = 1e9;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist[N];
int n, k;
int cnt;
vector<int> adj[N], res;
int u;

void dfs(int start) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
    }
    dist[start] = 0;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> u;
        while (u-- and u >= 0) {
            int v; cin >> v;
            adj[i].pb(v);
        }
    }
    dfs(k);
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != inf) {
            res.pb(i);
        }
    }
    cout << res.size() << '\n';
    for (auto x : res) {
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
    
    /*
    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);
    */

    logic();
}

/*
--/shouko\--
DRAFT:


------------
*/
