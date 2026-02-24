/*

3
1 1 1
1 2
2 1
3

2
1 1
2


*/


#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n;
int dp[N];

void init(void) {
    cin >> n;
}

namespace subtask {
    bool check() { return true; }
    void solve() {
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 6; ++j) {
                if (i - j >= 0) {
                    dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
                }
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
    if (subtask::check()) subtask::solve();

    return 0;
}
