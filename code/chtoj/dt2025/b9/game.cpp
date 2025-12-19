#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1e18
#define MAXN 100005
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 1, n)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define fi first
#define se second
#define pii pair<int, int>
#define task "GAME"

using namespace std;
const int N = 2e2 + 9;
int n, m, p;
int dp[N][N][N];

void logic() {
    cin >> n >> m >> p;
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= p; ++j) {
            dp[0][i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= p; ++k) {
                dp[i][j][k] = dp[i][j][k - 1];
                if (i - k >= 0) {
                    dp[i][j][k] += dp[i - k][j - 1][k];
                }
            }
        }
    }
    cout << dp[n][m][p];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    memset(dp, 0, sizeof(dp));
    logic();

    return 0;
}