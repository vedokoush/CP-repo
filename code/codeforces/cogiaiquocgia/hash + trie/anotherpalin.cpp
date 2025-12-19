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
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

int pw[N], pre[N], suf[N];
int n;
string s;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

int getHash(int l, int r) {
    if (l > r) return 0;
    return sub(pre[r], mul(pre[l - 1], pw[r - l + 1], mod), mod);
}

int getRevHash(int l, int r) {
    if (l > r) return 0;
    return sub(suf[l], mul(suf[r + 1], pw[r - l + 1], mod), mod);
}

bool isPalindrome(int l, int r) {
    return getHash(l, r) == getRevHash(l, r);
}

void solve() {
    cin >> n >> s;
    s = " " + s;
    int len = s.size() - 1;

    pw[0] = 1;
    for (int i = 1; i <= len; ++i) pw[i] = mul(pw[i - 1], base, mod);
    for (int i = 1; i <= len; ++i) pre[i] = add(mul(pre[i - 1], base, mod), s[i], mod);
    for (int i = len; i >= 1; --i) suf[i] = add(mul(suf[i + 1], base, mod), s[i], mod);

    int cnt = 0;
    for (int l = 1; l <= len; ++l) {
        for (int r = l; r <= len; ++r) {
            if (isPalindrome(l, r)) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';
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
