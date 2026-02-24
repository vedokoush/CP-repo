#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;

int n, x;
int c[N];
int dp[N];

void init(void) {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
}

namespace subtask {
    bool check() { return true; }
    void solve() {
        for (int i = 0; i <= x; ++i)
            dp[i] = inf;

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int sum = c[i]; sum <= x; ++sum) {
                dp[sum] = min(dp[sum], dp[sum - c[i]] + 1);
            }
        }
        if (dp[x] == inf) {
            cout << -1;
        }
        else cout << dp[x];
    }
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    if (subtask::check()) subtask::solve();

    return 0;
}
