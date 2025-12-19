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
#define task "COUPONS"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }
int n, k, m;
ii a[N];
int c[N];
int ans;

bool cmp(ii x, ii y) {
    return min(x.fi, x.se) <= min(y.fi, y.se);
}

bool check(int x) {
    for (int i = 1; i <= n; ++i) {
        c[i] = a[i].se - a[i].fi;
    }
    sort (c + 1, c + n + 1);
    for 
}

void solve() {
    cin >> n >> k >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
    }
    sort (a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; ++i) {
        // cout << a[i].fi << ' ' << a[i].se << '\n';
        if (k != 0) {
            if (a[i].fi == a[i].se) {
                c += a[i].se;
                --k;
                m -= a[i].se;
                ++ans;
            }
            else {
                m -= a[i].se;
                --k;
                ++ans;
            }
        }
        else {
            while (m - a[i].fi >= 0) {
                m -= a[i].fi;
                ++ans;
            }
        }
    }
    cout << ans;
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