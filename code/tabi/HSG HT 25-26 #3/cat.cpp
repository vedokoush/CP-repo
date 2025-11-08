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
const int N = 505;
const int inf = 1e18;

int dp[N][N];
int n, m;

void logic() {

    cin >> n >> m;

    for (int a = 1; a <= n; a++) {
        for (int b = 1; b <= m; b++) {
            if (a == b) dp[a][b] = 0;
            else {
                dp[a][b] = inf;
                for (int i = 1; i < a; i++) {
                    dp[a][b] = min(dp[a][b], dp[i][b] + dp[a - i][b] + 1);
                }
                for (int j = 1; j < b; j++) {
                    dp[a][b] = min(dp[a][b], dp[a][j] + dp[a][b - j] + 1);
                }
            }
        }
    }

    cout << dp[n][m];
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();

    return 0;
}

/*
--/shouko\--
*/