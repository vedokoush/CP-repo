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
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

int vis[N];
int a[N];
int d[N];
int dp[N];
int n;

void dfs(int u) {
    vis[u] = 1;
    int v = a[u];
    d[v] = d[u] + 1;
    if (!vis[v]) {
        dfs(v);
    } else if (vis[v] == 1) {
        int len = d[u] - d[v] + 1;
        for (int x = v; ; x = a[x]) {
            dp[x] = len;
            if (x == u) break;
        }
    }
    vis[u] = 2;
    if (!dp[u]) dp[u] = dp[v] + 1;
}



void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            d[i] = 1;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << dp[i] << '\n';
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();

    // execute;
    return 0;
}
  
/* shouko */