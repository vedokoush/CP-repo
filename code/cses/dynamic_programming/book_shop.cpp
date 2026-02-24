#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;
int n, x;
int h[N], s[N];
int dp[N];
int ans = -inf;

void init(void) {
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
    }
}

namespace subtask {
    void solve() {
        dp[0] = 0;
        for (int i = 1; i <= x; ++i) {
            dp[i] = -inf;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = x; j >= h[i]; --j) {
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
            }
        }
        int ans = *max_element(dp + 1, dp + x + 1);
        if (ans != -inf) cout << ans;
        else cout << 0;
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
