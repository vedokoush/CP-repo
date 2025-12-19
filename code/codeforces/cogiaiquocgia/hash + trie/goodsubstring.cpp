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
const int hmod1 = 1e9 + 11;
const int hmod2 = 2e9 + 7;
const int base = 311;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string s;
int k;
bool bad[300];
int pw1[N], pw2[N];
int pre1[N], pre2[N];
set<ii> res;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int mul(int a, int b, int mod) { return (a * b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }

ii getHash(int l, int r) {
    int H1 = sub(pre1[r], mul(pre1[l - 1], pw1[r - l + 1], hmod1), hmod1);
    int H2 = sub(pre2[r], mul(pre2[l - 1], pw2[r - l + 1], hmod2), hmod2);
    return {H1, H2};
}

void logic() {
    cin >> s;
    int n = s.size();
    s = ' ' + s;

    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        pw1[i] = mul(pw1[i - 1], base, hmod1);
        pw2[i] = mul(pw2[i - 1], base, hmod2);
    }

    for (int i = 1; i <= n; ++i) {
        pre1[i] = add(mul(pre1[i - 1], base, hmod1), s[i], hmod1);
        pre2[i] = add(mul(pre2[i - 1], base, hmod2), s[i], hmod2);
    }

    for (int i = 'a'; i <= 'z'; ++i) {
        char x; cin >> x;
        if (x == '0') bad[i] = true;
    }

    cin >> k;

    for (int l = 1; l <= n; ++l) {
        int sum = 0;
        for (int r = l; r <= n; ++r) {
            sum += bad[s[r]];
            if (sum > k) break;
            res.insert(getHash(l, r));
        }
    }

    cout << res.size() << '\n';
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

    logic();
    return 0;
}
