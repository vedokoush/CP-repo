#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
#define task ""

using namespace std;

const int N = 2e5 + 9;
const int inf = 1e18;

int a[N], dp[N][2]; 

void logic() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    a[n + 1] = a[n + 2] = 0;
    dp[n + 1][0] = dp[n + 1][1] = 0;
    dp[n + 2][0] = dp[n + 2][1] = 0;

    for (int i = n; i >= 1; --i) {
        dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
        dp[i][0] = a[i] + dp[i + 1][1];
        if (i + 1 <= n) dp[i][0] = min(dp[i][0], a[i] + a[i + 1] + dp[i + 2][1]);
    }

    cout << dp[1][0] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) logic();

    return 0;
}