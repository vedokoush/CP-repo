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
#define task "FROG"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int m, n, k;
int a[N][N];
int dp[N][N];
int trace[N][N];
int maxx = -inf;
int cot = -1;
vector<int> p(N);

void logic() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = -inf;
            trace[i][j] = -1;
        }
    }

    for (int j = 1; j <= n; ++j) {
        dp[1][j] = a[1][j];
    }

    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int t = max(1LL, j - k); t <= min(n, j + k); ++t) {
                if (dp[i][j] < dp[i - 1][t] + a[i][j]) {
                    dp[i][j] = dp[i - 1][t] + a[i][j];
                    trace[i][j] = t;
                }
            }
        }
    }

    for (int j = 1; j <= n; ++j) {
        if (dp[m][j] > maxx) {
            maxx = dp[m][j];
            cot = j;
        }
    }

    int cnt = m, v = cot;
    while (cnt >= 1) {
        p[cnt] = v;
        v = trace[cnt][v];
        cnt--;
    }

        cout << maxx << '\n';
    for (int i = 1; i <= m; ++i) {
        cout << p[i] << '\n';
    }        
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
