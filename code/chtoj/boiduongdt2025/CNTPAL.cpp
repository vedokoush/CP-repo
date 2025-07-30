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
#define task "CNTPAL"

using namespace std;
const int N = 5e3 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string s;
    int q;
int n;
int pre[N], pw[N], suf[N];
int is_pal[N][N], cnt[N][N];

int getHash(int l, int r) {
    if (l > r) return 0;
    return sub(pre[r], mul(pre[l - 1], pw[r - l + 1], mod), mod);
}

int getRevHash(int l, int r) {
    if (l > r) return 0;
    return sub(suf[l], mul(suf[r + 1], pw[r - l + 1], mod), mod);
}

bool check_pal(int l, int r) {
    return getHash(l, r) == getRevHash(l, r);
}

void solve() {
    cin >> s;
    s = ' ' + s;
    n = s.size() - 1;
    pw[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw[i] = mul(pw[i - 1], base, mod);
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = add(mul(pre[i - 1], base, mod), s[i], mod);
    }
    for (int i = n; i >= 1; --i) {
        suf[i] = add(mul(suf[i + 1], base, mod), s[i], mod);
    }

    for (int len = 1; len <= n; ++len) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            is_pal[i][j] = check_pal(i, j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            cnt[i][j] = cnt[i][j - 1] + is_pal[i][j];
        }
    }

    for (int j = 1; j <= n; ++j)
        for (int i = j - 1; i >= 1; --i)
            cnt[i][j] += cnt[i + 1][j];

    int q; cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << cnt[l][r] << '\n';
    }


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }

    solve();

    // execute;
    return 0;
}

/* shouko */
