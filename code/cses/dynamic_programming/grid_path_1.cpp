#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e3 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n;
int dp[N][N];
char c[N][N];

void init(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
        }
    }
}

namespace subtask {
    bool check() {
        return c[1][1] != '*';
    }
    void solve() {
        dp[1][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (c[i][j] == '*') {
                    continue;
                }
                if (i > 1) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                }
                if (j > 1) {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                }
            }
        }
        cout << dp[n][n];
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    if (subtask::check())subtask::solve();
    else cout << 0;

    return 0;
}
