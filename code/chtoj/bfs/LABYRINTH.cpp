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
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n, m;
int dist[N][N];
queue<ii> q;
ii st;
char a[N][N];
int mn = inf;
int x, y;
ii trace[N][N];
ii node;
ii tmp;
vector<ii> path;
int prei, prej;

bool check(int i, int j) {
    if (i == 1 or i == n or j == 1 or j == m){
        return true;
    }
    return false;
}

void bfs(pair<int, int> start) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dist[i][j] = inf;
        }
    }
    dist[start.fi][start.se] = 0;
    trace[start.fi][start.se] = {-1, -1};
    q.push(start);

    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        for (int i = 0; i <= 3; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u > 0 and u <= n and v > 0 and v <= m and a[u][v] != '#') {
                if (dist[u][v] > dist[x][y] + 1) {
                    dist[u][v] = dist[x][y] + 1;
                    trace[u][v] = {x, y};
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
            if (a[i][j] == '*') {
                st = {i, j};
            }
        }
    }
    bfs(st);
    node = {-1, -1};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (check(i, j)) {
                if (dist[i][j] < mn) {
                    mn = dist[i][j];
                    node = {i, j};
                }
            }
        }
    }
    if (mn == inf) {
        cout << 0;
    }
    else {
        tmp = node;
        while (tmp != ii(-1, -1)) {
            path.pb(tmp);
            tmp = trace[tmp.fi][tmp.se];
        }
        reverse(all(path));
        for (auto [i, j] : path) {
            // cout << prei << ' ' << prej << '\n';
            if (prej + 1 == j and prei == i) {
                cout << "E";
            }
            if (prej - 1 == j and prei == i) {
                cout << "W";
            }
            if (prej == j and prei + 1 == i) {
                cout << "S";
            }
            if (prej == j and prei - 1 == i) {
                cout << "N";
            }
            // cout << i << ' ' << j << '\n';
            prei = i, prej = j;
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
