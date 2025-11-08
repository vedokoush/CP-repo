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
#define task ""


using namespace std;
const int N = 1e5 + 9;
const int M = 1e3 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int n ,m;
int a[N];
int dp[N][115];
 
void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (a[1] == 0) {
        for (int i = 1; i <= m; ++i) {
            dp[1][i] = 1;
        }
    }
    else {
        dp[1][a[1]] = 1;    
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i] == 0) {
            for (int j = 1; j <=m; ++j) {
                dp[i][j] = add(add(dp[i - 1][j - 1], dp[i - 1][j]), dp[i - 1][j + 1]);
            }
        }
        else {
            dp[i][a[i]] = add(add(dp[i - 1][a[i]-1], dp[i-1][a[i]]),dp[i-1][a[i]+1]); 
        }
    }
    int ans = 0;
    for (int j = 1; j <= m; ++j) {
        ans = add(ans, dp[n][j]);
    }
    cout << ans;
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

fefefefefef
------------
*/
