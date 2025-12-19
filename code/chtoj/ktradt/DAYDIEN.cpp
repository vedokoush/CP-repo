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
#define task "daydien"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[N];
int r_a[N];
int dp[N], r_dp[N];
int f1[N], f2[N];
int res1 = 0, res2 = 0, res3 = 0;
int pos1, pos2;
int maxx = inf;
vector<int> ans1, ans2;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = -a[i];
    }

    for (int i = n; i >= 1; --i) {
        r_a[i] = a[n - i + 1];
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = lower_bound(f1 + 1, f1 + res1 + 1, a[i]) - f1;
        f1[dp[i]] = a[i];
        if (dp[i] > res1) {
            res1++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        r_dp[i] = lower_bound(f2 + 1, f2 + res2 + 1, r_a[i]) - f2;
        f2[r_dp[i]] = r_a[i];
        if (r_dp[i] > res2) {
            res2++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dp[i] + r_dp[n - i + 1] - 1 > res3) {
            res3 = dp[i] + r_dp[n - i + 1] - 1;
            pos1 = i;
            pos2 = n - i + 1;
        }
    }
    cout << res3 << '\n';
    res1 = dp[pos1];
    res2 = r_dp[pos2];
    maxx = inf;
    for (int i = pos1; i >= 1; --i) {
        if (dp[i] == res1 and a[i] < maxx) {
            ans1.pb(-a[i]);
            res1--;
            maxx = a[i];
        }
    }
    reverse(all(ans1));
    for (auto x : ans1) {
        cout << x << ' ';
    }
    maxx = inf;
    for (int i = pos2; i >= 1; --i) {
        if (r_dp[i] == res2 and r_a[i] < maxx) {
            ans2.pb(-r_a[i]);
            res2--;
            maxx = r_a[i];
        }
    }
    bool c = true;
    for (auto x : ans2) {
        if (c) {
            c = false;
            continue;
        }
        cout << x << ' ';
    }
    cout << '\n';
    
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
