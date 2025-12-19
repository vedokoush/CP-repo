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
#define task "LABYRINTH"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k;
int dist[N];
queue<int> q;
vector<int> adj[N];
bool lockk[N];
int par[N];

// void bfs(int start) {
//     for (int i = 1; i <= n; ++i) {
//         dist[i] = inf;
//     }
//     dist[start] = 0;
//     q.push(start);
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (auto v : adj[u]) {
//             if (lockk[v] == false) {
//                 if (dist[v] > dist[u] + 1) {
//                     dist[v] = dist[u] + 1;
//                     q.push(v);
//                 }
//             }
//         }
//     }
// }

int acs(int u) {
    if (par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        par[x] = y;
    }
}

void logic() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        lockk[i] = true;
    }
    while (m--) {
        int u,v ; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        // join(u, v);
    }
    while (k--) {
        char c; cin >> c;
        if (c == 'X') {
            int x; cin >> x;
            lockk[x] = false;
            for (auto v : adj[x]) {
                if (lockk[v] == false) {
                    join(x, v);
                }
            }
        }
        else {
            int x, y; cin >> x >> y;
            if (acs(x) == acs(y)) {
                cout << "Y";
            }
            else {
                cout << "N";
            }
            // bfs(x);
            // if (dist[y] != inf) {
            //     cout << "Y";
            // }
            // else {
            //     cout << "N";
            // }
        }
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

