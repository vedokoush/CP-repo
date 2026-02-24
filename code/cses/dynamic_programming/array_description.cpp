/// |a[i] - a[i - 1]| <= 1
/// dp[i][x]: so cach tao day co i gia tri trong do gia tri thu i la x
/// -> a[i] = x
/// dp[4][3] = 2
/// |x - a[i - 1]| <= 1
/// -1 <= x - a[i - 1] <= 1
/// x - 1 <= a[i - 1] <= x + 1
/// -> a[i - 1] {x - 1, x, x + 1}

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e3 + 3;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
int a[N];
int dp[N][N];

void init(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
}

namespace subtask {
    void solve() {
        if (a[1] == 0) {
            for (int j = 1; j <= m; ++j)
                dp[1][j] = 1;
        } else {
            dp[1][a[1]] = 1;
        }

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i] == 0 || a[i] == j) {
                    dp[i][j] = dp[i-1][j];
                    if (j > 1) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                    }
                    if (j < m) {
                        dp[i][j] = (dp[i][j] + dp[i-1][j+1]) % mod;
                    }
                }
            }
        }

        int ans = 0;
        for (int j = 1; j <= m; ++j)
            ans = (ans + dp[n][j]) % mod;

        cout << ans;
    }

}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    subtask::solve();

    return 0;
}
