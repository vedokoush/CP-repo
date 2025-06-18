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
const int mod = 2e9 + 11;
const int hmod1 = 1e9 + 11;
const int hmod2 = 2e9 + 7;
const int base = 311;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline int add(int a, int b, int mod) {return (a + b) % mod;}
inline int mul(int a, int b, int mod) {return (a * b) % mod;}
inline int sub(int a, int b, int mod) {return ((a - b) % mod + mod) % mod;}
string s, p;
int k;
int n, m;
int pw[N];
int pre[N];
int H;
vector<ii> v;

int getHash(int l, int r) {
    return sub(pre[r], mul(pre[l - 1], pw[r - l + 1], mod), mod);
}

void logic() {
    getline(cin, s);
    getline(cin, p);
    cin >> k;
    n = s.size(), m = p.size();
    s = ' ' + s;
    p = ' ' + p;


    pw[0] = 1;
    for (int i = 1; i <= max(n, m); ++i) {
        pw[i] = mul(pw[i - 1], base, mod);
    }
    for (int i = 1; i <= n; ++i) {
        pre[i] = add(mul(pre[i - 1], base, mod), s[i], mod);
    }
    for (int i = 1; i <= m; ++i) {
        H = add(mul(H, base, mod), p[i], mod);
    }

    for (int r = m; r <= n; ++r) {
        int l = r - m + 1;
        if (getHash(l, r) == H) {
            v.pb({l, r});
        }
    }
    
    sort(all(v));

    int dist = k - m;
    int ans = 0;
    int l = v[0].fi - dist;
    int rl = l - 1;
    int r = v[0].se + dist;

    for (int i = 1; i < v.size(); ++i) {
        int u = v[i].fi - dist;
        int v_ = v[i].se + dist;

        if (u <= r) {
            r = max(r, v_);
        } else {
            ans += (r - l + 1) - k + 1;
            l = u;
            r = v_;
        }
    }
    ans += (r - l + 1) - k + 1;
    if (rl < 0) cout << ans + rl << '\n';
    else {
        cout << ans << '\n';
    }


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
