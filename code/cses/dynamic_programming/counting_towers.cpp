#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, m;
int a[N];
int dp[N][2];

void init(void) {
    cin >> n;
}

namespace subtask {
    void init(void) {

        dp[1][0] = 1;
        dp[1][1] = 1;

        for (int i = 2; i < N; ++i) {
            dp[i][0] = (2 * dp[i - 1][0] + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i - 1][0] + 4 * dp[i - 1][1]) % mod;
        }
    }

    void solve(void) {
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }
}


main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    subtask::init();
    int t; cin >> t;
    while (t--) {
        init();
        subtask::solve();
    }

    return 0;
}

