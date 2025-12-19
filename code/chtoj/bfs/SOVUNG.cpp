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
#define task "SOVUNG"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m, n, k;
int a[N][N];
bool vis[N][N];
queue<ii> q;
int cnt;

void bfs(ii start) {
    vis[start.fi][start.se] = true;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        for (int i = 0; i <= 3; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u > 0 and u <= m and v > 0 and v <= n and a[u][v] != 1 and !vis[u][v]) {
                vis[u][v] = true;
                q.push({u, v});
            }
        }
    }
}

void logic() {
    cin >> m >> n >> k;
    while (k--) {
        int x, y, z, t; cin >> x >> y >> z >> t;
        if (x == z) {
            for (int i = y; i <= t; ++i) {
                a[x][i] = 1;
            }
        }
        if (y == t) {
            for (int i = x; i <= z; ++i) {
                a[i][y] = 1;
            }
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            vis[i][j] = false;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j] != 1 and !vis[i][j]) {
                ++cnt;
                ii start = {i, j};
                bfs(start);
            }
        }
    }
    cout << cnt;
    // for (int i = 1; i <= m; ++i) {
    //     for (int j = 1; j <= n; ++j) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
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
