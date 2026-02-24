#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

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
        dp[0] = 1;
        for (int sum = 1; sum <= x; ++sum) {
            for (int i = 1; i <= n; ++i) {
                if (sum - c[i] >= 0)
                    dp[sum] = (dp[sum] + dp[sum - c[i]]) % mod;
            }
        }
        cout << dp[x];
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

