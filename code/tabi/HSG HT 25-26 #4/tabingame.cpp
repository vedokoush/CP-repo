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
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int dp[N][2];
int a[N];

void init() {
    for (int i = 1; i <= N; ++i) {
        dp[i][0] = dp[i][1] = 0;
    }
}

void logic() {
    int n; cin >> n;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; --i) {
        /// th1: tuan anh di
        dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
        
        /// th2: duc di
        int c = a[i];
        if (i + 1 > n) {
            c = 0;
        }
        dp[i][0] = min(a[i] + dp[i + 1][1], a[i] + c + dp[i + 2][1]);
    }
    cout << dp[1][0] << '\n';
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

    int t; cin >> t;
    while (t--) {
    logic();
    }

    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/
