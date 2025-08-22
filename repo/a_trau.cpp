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
#define task "PADBLE"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1000000007;
const int base = 311;

int pw[N], pre[N], suf[N];
int rpre[N];
string rs;
int prefA[N], prefB[N];
int n;
string s;
int ans = -1;
int cnt = 0;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

int getHash(int l, int r) {
    if (l > r) return 0;
    return sub(pre[r], mul(pre[l - 1], pw[r - l + 1], mod), mod);
}

int getRevHash(int l, int r) {
    if (l > r) return 0;
    int L = n - r + 1;
    int R = n - l + 1;
    return sub(rpre[R], mul(rpre[L - 1], pw[R - L + 1], mod), mod);
}

bool check(int l, int r) {
    return getHash(l, r) == getRevHash(l, r);
}

bool XDX(int l, int r) {
    int len = r - l + 1;
    if (len & 1) {
        return false;
    }
    int mid = l + len / 2 - 1;
    if (!check(l, mid)) {
        return false;
    }
    if (!check(mid + 1, r)) {
        return false;
    }
    bool checka = (prefA[r] - prefA[l - 1]) > 0;
    bool checkb = (prefB[r] - prefB[l - 1]) > 0;
    return checka && checkb;
}

void sub12() {
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            if (XDX(l, r)) {
                int len = r - l + 1;
                if (len > ans) {
                    ans = len;
                    cnt = 1;
                } else if (len == ans) {
                    cnt++;
                }
            }
        }
    }

    if (ans == -1) cout << -1;
    else cout << ans << " " << cnt;
}

void sub3() {
    for (int i = 2; i <= n; ++i) {
        int maxr = min(i - 1, n - i + 1);
        int l = 0, r = maxr, tmp = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int ls = i - mid;
            int rs = i + mid - 1;
            if (XDX(ls, rs)) {
                tmp = rs - ls + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (tmp != -1) ans = max(ans, tmp);
    }
    for (int i = 1; i <= n; ++i) {
        if (XDX(i, i + ans - 1)) {
            ++cnt;
            // cout << i << ' ' << i + ans << '\n';
        }
    }
    if (ans == -1) cout << -1;
    else cout << ans << " " << cnt;
}

void solve() {
    cin >> s;
    s = " " + s;
    n = s.size() - 1;

    pw[0] = 1;
    for (int i = 1; i <= n; ++i) pw[i] = mul(pw[i - 1], base, mod);
    for (int i = 1; i <= n; ++i) pre[i] = add(mul(pre[i - 1], base, mod), s[i], mod);
    string g = s.substr(1);
    string rev = string(g.rbegin(), g.rend());
    rs = " " + rev;

    for (int i = 1; i <= n; ++i) rpre[i] = add(mul(rpre[i - 1], base, mod), rs[i], mod);

    for (int i = n; i >= 1; --i) suf[i] = add(mul(suf[i + 1], base, mod), s[i], mod);

    for (int i = 1; i <= n; ++i) {
        prefA[i] = prefA[i - 1] + (s[i] == 'a');
        prefB[i] = prefB[i - 1] + (s[i] == 'b');
    }
    
    sub12();


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

        freopen("a.inp", "r", stdin);
        freopen("a.ans", "w", stdout);

    solve();

    // execute;
    return 0;
}

