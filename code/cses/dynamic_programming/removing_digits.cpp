#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;

int n;
int dp[N];

void init(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        dp[i] = inf;
    }
}

namespace subtask {
    void solve() {
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            int x = i;
            while (x != 0) {
                int d = x % 10;
                x /= 10;
                if (i - d >= 0)
                    dp[i] = min(dp[i], dp[i - d] + 1);
            }
        }
        cout << dp[n];
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
