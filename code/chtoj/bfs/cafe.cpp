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
#define task "CAFE"


using namespace std;
const int N = 1e3 + 99;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
ii startT, startP;
vector<vector<int>> a, distT, distP;
int n, m; 

void bfsT(ii start) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            distT[i][j] = inf;
        }
    }
    distT[start.fi][start.se] = 0;
    deque<ii> dq; 
    int cost;
    dq.push_back(start);

    while (!dq.empty()) {
        int x = dq.front().fi;
        int y = dq.front().se;
        dq.pop_front();

        for (int i = 0; i <= 3; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u > 0 and u <= n and v > 0 and v <= m) {
                if (a[x][y] == 2 or a[x][y] == 3) {
                    cost = 0;
                }
                else cost = 1;
                if (distT[u][v] > distT[x][y] + cost) {
                    distT[u][v] = distT[x][y] + cost;
                    if (cost == 0) {
                        dq.push_front({u, v});
                    }
                    else {
                        dq.push_back({u, v});
                    }
                }
            }
        }
    }
}

void bfsP(ii start) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            distP[i][j] = inf;
        }
    }
    distP[start.fi][start.se] = 0;
    deque<ii> dq; 
    int cost;
    dq.push_back(start);

    while (!dq.empty()) {
        int x = dq.front().fi;
        int y = dq.front().se;
        dq.pop_front();

        for (int i = 0; i <= 3; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u > 0 and u <= n and v > 0 and v <= m) {
                if (a[x][y] == 1 or a[x][y] == 3) {
                    cost = 0;
                }
                else cost = 1;
                if (distP[u][v] > distP[x][y] + cost) {
                    distP[u][v] = distP[x][y] + cost;
                    if (cost == 0) {
                        dq.push_front({u, v});
                    }
                    else {
                        dq.push_back({u, v});
                    }
                }
            }
        }
    }
}


void logic() {
    int minn = inf;
    cin >> n >> m;

    a.assign(n + 1, vector<int>(m + 1));
    distT.assign(n + 1, vector<int>(m + 1, inf));
    distP.assign(n + 1, vector<int>(m + 1, inf));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    startT = {1, 1};
    startP = {n, m};
    bfsT(startT);
    bfsP(startP);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            minn = min(minn, distT[i][j] + distP[i][j]);
        }
    }
    cout << minn << '\n';
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

    int q; cin >> q;
    while (q--) {
        logic();
    }

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/
