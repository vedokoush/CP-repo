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
#define task ""

using namespace std;

const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int dx[] = {1, -1, 2, -2, 1, -1, 2, -2};
int dy[] = {2, -2, 1, -1, -2, 2, -1, 1};

int n, m;
int x1, z1, x2, y2;
int dist[N][N];
queue<ii> q;

void bfs(ii start) {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            dist[i][j] = inf;

    dist[start.fi][start.se] = 0;
    q.push(start);

    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        for (int i = 0; i < 8; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];

            if (u > 0 && u <= n && v > 0 && v <= m) {
                if (dist[u][v] > dist[x][y] + 1) {
                    dist[u][v] = dist[x][y] + 1;
                    q.push({u, v});
                }
            }
        }
    }
}

void logic() {
    cin >> n >> m;
    cin >> x1 >> z1;
    cin >> x2 >> y2;

    bfs({x1, z1});

    if (dist[x2][y2] == inf) cout << -1;
    else cout << dist[x2][y2];

    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

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