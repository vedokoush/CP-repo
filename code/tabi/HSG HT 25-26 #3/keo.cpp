#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define task ""
using namespace std;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
const int M = 105;

int n, k;
int a[M];
int dp[M][N];
int f[N];

int add(int a, int b) { return (a + b) % MOD; }
int sub(int a, int b) { return ((a - b) % MOD + MOD) % MOD; }

void logic(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){ 
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i){
        f[0] = dp[i - 1][0];
        for (int j = 1; j <= k; ++j) {
            f[j] = add(f[j - 1], dp[i - 1][j]);
        }

        for (int j = 0; j <= k; ++j) {
            dp[i][j] = f[j];
            if (j - a[i] - 1 >= 0) {
                dp[i][j] = sub(dp[i][j], f[j - a[i] - 1]);
            }
        }
    }

    cout << dp[n][k] % MOD << "\n";
    // execute;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();
    return 0;
}