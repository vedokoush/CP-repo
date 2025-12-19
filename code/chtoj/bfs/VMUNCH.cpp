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
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
pair<int, int> start;
int dist[N][N];
queue<pair<int, int>> q;
char a[N][N];

void bfs(pair<int, int> start) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
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
            if (u > 0 and u <= n and v > 0 and v <= m and a[u][v] != '*') {
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
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'C') {
                start = {i, j};
            }
        }
    }
    bfs(start);
    if (dist[1][1] == inf) {
        cout << "zero";
    }
    else {
        cout << dist[1][1];
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
