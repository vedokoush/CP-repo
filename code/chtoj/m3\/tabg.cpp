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
#define task "TABG"


using namespace std;
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int m, n;
int a[N][N];
int dpt[5], dp[5];
int cnt;
 
void sub2 () {
    ms(dpt, -inf);
    ms(dp, -inf);
    dpt[0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int k = 0; k < 4; ++k) {
            dp[k] = -inf;
        }
        for (int j = 0; j < 4; ++j) {
            if (dpt[j] == -inf) continue;
            dp[0] = max(dp[0], dpt[j]);
            if ((a[1][i] == 1 || a[1][i] == 3) && ((j & 1) == 0)) {
                dp[2] = max(dp[2], dpt[j] + 1);
            }
            if ((a[1][i] == 2 || a[1][i] == 3) && ((j & 2) == 0)) {
                dp[1] = max(dp[1], dpt[j] + 1);
            }
        }
        for (int k = 0; k < 4; ++k) {
            dpt[k] = dp[k];
        }
    }
    int ans = 0;
    for (int k = 0; k < 4; ++k) {
        ans = max(ans, dpt[k]);
    }
    cout << ans;
}

void sub3() {
    // cout << (n / 2 + n % 2) * (m / 2 + m % 2) * 2 << '\n' 
    //      << m * (n / 2 + n % 2);
    int i = (n / 2 + n % 2) * (m / 2 + m % 2) * 2;
    int j = m * (n / 2 + n % 2);
    if (i >= j) cout << i;
    else cout << j;
}

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 3) {
                ++cnt;
            }
        }
    }
    if (m == 1) {
        sub2();
    }
    else if (cnt == n * m) {
        sub3();
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
