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

int n, m;
string a, b;
int t;
int preA[N], preB[N], pw[N];

int getHashA(int l, int r) {
    return sub(preA[r], mul(preA[l - 1], pw[r - l + 1], mod), mod);
}

int getHashB(int l, int r) {
    return sub(preB[r], mul(preB[l - 1], pw[r - l + 1], mod), mod);
}

bool check(int l1, int r1, int l2, int r2) {
    if (r1 - l1 != r2 - l2) return false;
    return getHashA(l1, r1) == getHashB(l2, r2);
}

void logic() {
    cin >> n >> m;
    cin >> a >> b;
    a = ' ' + a;
    b = ' ' + b;
    pw[0] = 1;
    preA[0] = preB[0] = 0;
    for (int i = 1; i <= max(n, m); ++i) {
        pw[i] = mul(pw[i - 1], base, mod);
    }
    for (int i = 1; i <= n; ++i) {
        preA[i] = add(mul(preA[i - 1], base, mod), a[i], mod);
    }
    for (int i = 1; i <= m; ++i) {
        preB[i] = add(mul(preB[i - 1], base, mod), b[i], mod);      
    }
    cin >> t; while (t--) {
        int l, r, u, v; cin >> l >> r >> u >> v;
        if (check(l, r, u, v)) {
            cout << "=";
            continue;
        }

        int lo = 1, hi = min(r - l + 1, v - u + 1), pos = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(l, l + mid - 1, u, u + mid - 1)) {
                pos = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (l + pos > r) cout << "<";
        else if (u + pos > v) cout << ">";
        else if (a[l + pos] < b[u + pos]) cout << "<";
        else cout << ">";
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
