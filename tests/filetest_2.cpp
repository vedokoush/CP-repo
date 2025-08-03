#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4 * 1e4 + 5;
const int INF = 1e18;

int n, a, b, h[205];
int dp[205][N][2], pre[205];

void logic() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        pre[i] = pre[i - 1] + h[i];
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= a; ++j) {
            dp[i][j][0] = dp[i][j][1] = INF;
        }
    }

    if (h[1] <= a) dp[1][h[1]][0] = 0;
    if (h[1] <= b) dp[1][0][1] = 0;

    for (int i = 2; i <= n; i++) {
        int sum = pre[i];
        for (int sa = 0; sa <= min(sum, a); sa++) {
            int sb = sum - sa;
            if (sb > b) continue;

            if (sa >= h[i]) {
                dp[i][sa][0] = min(dp[i][sa][0], dp[i - 1][sa - h[i]][0]);
                dp[i][sa][0] = min(dp[i][sa][0], dp[i - 1][sa - h[i]][1] + min(h[i], h[i - 1]));
            }

            dp[i][sa][1] = min(dp[i][sa][1], dp[i - 1][sa][1]);
            dp[i][sa][1] = min(dp[i][sa][1], dp[i - 1][sa][0] + min(h[i], h[i - 1]));
        }
    }

    int res = INF;
    for (int sa = 0; sa <= a; ++sa) {
        res = min({res, dp[n][sa][0], dp[n][sa][1]});
    }
    cout << (res == INF ? -1 : res) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }

    logic();
    return 0;
}