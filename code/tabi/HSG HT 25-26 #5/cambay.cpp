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
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int a[N];
bool m[N];
int cnt[N], f[N];

void logic() {
    ms(cnt, 0);
    ms(f, 0);

    int n; 
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= n) ++f[a[i]];
    }

    for (int x = 1; x <= n; ++x) {
        if (f[x] == 0) continue;
        for (int m = x; m <= n; m += x) {
            cnt[m] += f[x];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, cnt[i]);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int t; cin >> t;
    while (t--) {
    logic();
    }

    /// 
    return 0;
}