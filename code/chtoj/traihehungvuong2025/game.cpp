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
#define task "GAME"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e3 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, t, a, b;
int ans;
int k[N];
int cnt;
int dp[M][M];
bool d[M][M];

void sub1() {
    for (int i = 1; i <= n; ++i) {
        if (t - a >= 0) {
            t -= a;
            ans += k[i];
        }
        else {
            break;
        }
    }
    cout << ans;
}

void sub2() {
    for (int i = 1; i <= n; ++i) {
        for (int ti = 1; ti <= t; ++ti) {
            dp[i][ti] = -inf;
            d[i][ti] = false;
        }
    }
    
    if (a <= t) {
        dp[1][a] = k[1];
        d[1][a] = true;
    }
    if (b <= t) {
        dp[1][b] = 0;
        d[1][b] = true;
    }
    
    int ans = 0;
    
    for (int i = 2; i <= n; ++i) {
        for (int ti = 0; ti <= t; ++ti) {
            if (ti >= a and d[i - 1][ti - a]) {
                if (dp[i][ti] < dp[i - 1][ti - a] + k[i]) {
                    dp[i][ti] = dp[i - 1][ti - a] + k[i];
                    d[i][ti] = true;
                }
            }
            
            if (ti >= b && d[i-1][ti-b]) {
                if (dp[i][ti] < dp[i - 1][ti - b]) {
                    dp[i][ti] = dp[i - 1][ti - b];
                    d[i][ti] = true;
                }
            }
            
            if (d[i][ti]) {
                ans = max(ans, dp[i][ti]);
            }
        }
    }
    
    for (int ti = 0; ti <= t; ++ti) {
        if (d[n][ti]) {
            ans = max(ans, dp[n][ti]);
        }
    }
    
    cout << ans;
}



void logic() {
    cin >> n >> t >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (k[i] <= k[i - 1]) {
            ++cnt;
        }
    }
    if (cnt == n - 1) {
        sub1();
    }
    else if (n <= 1e3 and t <= 1e3) {
        sub2();
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
    
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/
