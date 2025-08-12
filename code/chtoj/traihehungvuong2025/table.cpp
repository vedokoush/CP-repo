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
#define task "TABLE"


using namespace std;
const int N = 1e3 + 9;
const int M = 30;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int m, n;
int a[N][N];
int mp[M][M][M][M];
bool check[M][M][M][M];
int dp[M][M][M][M];
int ans = -inf;
                    map<int,int> cnt;

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int i = 1; i <= m; ++i) {
                for (int j = i; j <= m; ++j) {
                    check[i][j][l][r] = true;
                    dp[i][j][l][r] = -1;
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = i; j <= m; ++j) {
            cnt.clear();
            int r = 1;
            for (int l = 1; l <= n; ++l) {
                while (r <= n) {
                    bool dup = false;
                    for (int row = i; row <= j; ++row) {
                        if (++cnt[a[row][r]] > 1) { dup = true; }
                    }
                    if (dup) {
                        for (int row = i; row <= j; ++row) cnt[a[row][r]]--;
                        break;
                    }
                    ++r;
                }
                check[i][j][l][r-1] = false;
                for (int row = i; row <= j; ++row) {
                    cnt[a[row][l]]--;
                }
            }
        }
    }
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int i = 1; i <= m; ++i) {
                for (int j = i; j <= m; ++j) {
                    if (check[i][j][l][r] == false) {
                        dp[i][j][l][r] = (r - l + 1) * (j - i + 1);
                    }
                }
            }
        }
    }
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int i = 1; i <= m; ++i) {
                for (int j = i; j <= m; ++j) {
                    ans = max(ans, dp[i][j][l][r]);
                }
            }
        }
    }
    cout << ans;
    
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

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/
