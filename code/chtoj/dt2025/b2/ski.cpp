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
#define task "SKI"

using namespace std;
const int N = 505;
const int inf = 1e18;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, t, d;
int h[N][N], s[N][N];
bool vis[N][N];

int bfs(int x, int y) {
    ms(vis, 0);
    queue<ii> q;
    q.push({x, y});
    vis[x][y] = true;
    int cnt = 0;

    while (!q.empty()) {
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();

        for (int i = 0; i <= 3; ++i) {
            int nx = u + dx[i];
            int ny = v + dy[i];
            if (nx >= 1 and nx <= n and ny >= 1 and ny <= m) {
                if (!vis[nx][ny] and abs(h[nx][ny] - h[u][v]) <= d) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                    cnt++;
                }
            }
        }
    }

    return cnt;
}

void logic() {
    cin >> n >> m >> t;
    d = 4;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> h[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> s[i][j];
        }
    }

    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == 1) {
                res.pb(bfs(i, j));
            }
        }
    }

    sort(all(res), greater<>());
    int ans = 0;
    for (int i = 0; i < min(t, (int)res.size()); ++i) {
        ans += res[i];
    }

    cout << ans << '\n';
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

------------
*/