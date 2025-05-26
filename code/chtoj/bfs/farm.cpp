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
#define task "FARM"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int m ,n;
char a[N][N];
bool vis[N][N];
ii start;
queue<ii> q;
int c, f; 
int tc = 0, tf = 0;

void bfs(ii start) {
    c = 0, f = 0;
    vis[start.fi][start.se] = true;
    q.push(start);

    if (a[start.fi][start.se] == 'c') ++c;
    if (a[start.fi][start.se] == 'f') ++f;

    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        for (int i = 0; i <= 3; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u > 0 and u <= m and v > 0 and v <= n and a[u][v] != '#' and !vis[u][v]) {
                if (a[u][v] == 'c') ++c;
                if (a[u][v] == 'f') ++f;
                q.push({u, v});
                vis[u][v] = true;
            }
        }
    }

    if (c > f) tc += c;
    else tf += f;
}

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            vis[i][j] = false;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!vis[i][j] && a[i][j] != '#') {
                start = {i, j};
                bfs(start);
            }
        }
    }
    cout << tf << ' ' << tc << '\n';
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/
