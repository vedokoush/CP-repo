#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define Is(mask, pos) (mask & (1LL << pos))
#define On(mask, pos) (mask  (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';

/*
  .-')    ('-. .-.                          .-. .-')
 ( OO ). ( OO )  /                          \  ( OO )
(_)---\_),--. ,--. .-'),-----.  ,--. ,--.   ,--. ,--.  .-'),-----.
/    _ | |  | |  |( OO'  .-.  ' |  | |  |   |  .'   / ( OO'  .-.  '
\  :` `. |   .|  |/   |  | |  | |  | | .-') |      /, /   |  | |  |
 '..`''.)|       |\_) |  |\|  | |  |_|( OO )|     ' _)\_) |  |\|  |
.-._)   \|  .-.  |  \ |  | |  | |  | | `-' /|  .   \    \ |  | |  |
\       /|  | |  |   `'  '-'  '('  '-'(_.-' |  |\   \    `'  '-'  '
 `-----' `--' `--'     `-----'   `-----'    `--' '--'      `-----'
*/

#define task "SPESS"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int base = 311;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int n, k;
int q;
int a[N];
int cnt;
int pre[N];
int maxx = 0;
int dp[N][N];
int dp1[N][N];
int ans = -inf;

//void ql(int i, int sum) {
//    if (sum > k) return;
//    if (i > n) {
//        if (sum <= k) ++cnt;
//    }
//    else {
//        ql(i + 1, sum);
//        ql(i + 1, sum + a[i]);
//    }
//}

int f(int i, int sum) {
    if (i > n) return 0;
    if (sum > k) return -inf;
    if (dp[i][sum] != -1) return dp[i][sum];
    int res = f(i + 1, sum);
    if (sum + a[i] <= k) {
        res = max(res, 1 + f(i + 1, sum + a[i]));
    }
    return dp[i][sum] = res;
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ms(dp, -1);
    cout << f(1, 0) << '\n';
    dp1[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = f(1, 0); j >= 1; j--) {
            for (int s = k; s >= a[i]; s--) {
                dp1[j][s] = dp1[j][s] + dp1[j - 1][s - a[i]];
            }
        }
    }
    for (int i = 0; i <= k; ++i) {
        cnt += dp1[f(1, 0)][i];
    }
    cout << cnt;

    // execute;
}

/*

pre[j] - pre[i]


*/


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);

    logic();

    return 0;
}
