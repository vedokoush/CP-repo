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
// dont copy my flow dude
#define task "SDCAR"

using namespace std;
const int N = 1e3 + 9;
const int M = 2e6 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int m, n, k;
bool a[N][N];
int dp[N][N];
int f[M], invf[M];

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init(int num) {
    f[0] = 1;
    for (int i = 1; i <= num; ++i) f[i] = f[i - 1] * i % mod;
    invf[num] = power(f[num], mod - 2);
    for (int i = num; i >= 1; --i) invf[i - 1] = invf[i] * i % mod;
}

int C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return f[n] * invf[k] % mod * invf[n - k] % mod;
}

void sub1() {
    ms(dp, 0);
    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i][j]) { dp[i][j] = 0; continue; }
            if (i > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[m][n];
}

void sub2() {
    int num = m + n;
    init(num);
    cout << C(m + n - 2, m - 1);
}

void sub3(int x, int y) {
    int num = m + n;
    init(num);
    int sum = C(m + n - 2, m - 1);
    int r = C(x + y - 2, x - 1) * C((m - x) + (n - y), m - x) % mod;
    int ans = ((sum - r + mod) % mod) % mod;
    cout << ans;
}

void logic() {
    cin >> m >> n >> k;
    vector<ii> adj;
    for (int i = 1; i <=m; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = false;
        }
    }
    for (int i = 1; i <= k; ++i) {
        int u, v; cin >> u >> v;
        a[u][v] = true;
        adj.pb({u,v});
    }
    if (k == 0) {
        sub2();
    } else if (k == 1) {
        sub3(adj[0].fi, adj[0].se);
    } else {
        sub1();
    }
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    
    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/
