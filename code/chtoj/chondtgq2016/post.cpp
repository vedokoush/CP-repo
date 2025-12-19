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
#define task "POST"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};


int dist[N][N];
queue<ii> q;
int n;
ii start;
int a[N][N];
char c[N][N];
vector<ii> ks;
vector<int> v;
bool vis[N][N];
int cntK = 0;

bool check(int l, int r) {
    if (cntK == 0) return true;
    if (a[start.fi][start.se] < l || a[start.fi][start.se] > r) return false;

    ms(vis, 0);
    queue<ii> q;
    q.push(start);
    vis[start.fi][start.se] = true;
    int tkn = 0;

    while (!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();
        if (c[x][y] == 'K') {
            ++tkn;
            if (tkn == cntK) return true;
        }
        for (int k = 0; k < 8; ++k) {
            int u = x + dx[k];
            int v2 = y + dy[k];
            if (u >= 1 && u <= n && v2 >= 1 && v2 <= n && !vis[u][v2]) {
                if (a[u][v2] >= l && a[u][v2] <= r) {
                    vis[u][v2] = true;
                    q.push({u, v2});
                }
            }
        }
    }
    return false;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
            if (c[i][j] == 'P') {
                start = {i, j};
            }
            if (c[i][j] == 'K') {
                ks.pb({i, j});
                ++cntK;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            v.pb(a[i][j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if (cntK == 0) {
        cout << 0 << '\n';
        return;
    }

    int ans = (int)inf;
    int i = 0, j = 0;
    while (i < (int)v.size() && j < (int)v.size()) {
        if (check(v[i], v[j])) {
            ans = min(ans, v[j] - v[i]);
            ++i;
        } else {
            ++j;
        }
    }
    cout << ans << '\n';
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
