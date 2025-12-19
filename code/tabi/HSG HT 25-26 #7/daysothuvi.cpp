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

int a[N];
int dp[N];


void logic() {
    int n; 
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0, len = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == a[i - 1]) len++;
        else {
            res += len / 2;
            len = 1;
        }
    }
    res += len / 2;

    cout << res << '\n';
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

dp[i]: so luong thao tac bien doi it nhat

xét i:
    th1: biến đổi
        dp[i] = dp[i - 1] + 1
    th2: không biến đổi
        dp[i] = dp[i - 1]

        hmm

------------
*/
