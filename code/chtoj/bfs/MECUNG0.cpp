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
#define task "MECUNG0"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m, n, k;
int dist[N][N];
queue<ii> q;
int x, y;
ii st;
int a[N][N];

void bfs(pair<int, int> start) {
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dist[i][j] = inf;
        }
    }
    dist[start.fi][start.se] = 0;
    q.push(start);
    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        
        for (int i = 0; i <= 3; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u > 0 and u <= m and v > 0 and v <= n and a[u][v] != 1) {
                if (dist[u][v] > dist[x][y] + 1) {
                    dist[u][v] = dist[x][y] + 1;
                    q.push({u, v});
                }
            }
        }
    }
}

void logic() {
    cin >> m >> n >> k;
    cin >> x >> y;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    st = {x, y};
    bfs(st);
    while (k--) {
        int u, v; cin >> u >> v;
        if (dist[u][v] != inf) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';  
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
