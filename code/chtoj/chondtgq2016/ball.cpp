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
#define task "BALL"

using namespace std;
const int N = 2000 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int mis[N];
int f[N + 5], f1[N + 5];

int pw(int a, long long e) {
    int r = 1 % mod;
    while (e) {
        if (e & 1) r = mul(r, a);
        a = mul(a, a);
        e >>= 1;
    }
    return r;
}

void init() {
    f[0] = 1;
    for (int i = 1; i <= N; ++i) f[i] = mul(f[i - 1], i % mod);
    f1[N] = pw(f[N], mod - 2);
    for (int i = N; i >= 1; --i) f1[i - 1] = mul(f1[i], i % mod);
}

int nPr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return mul(f[n], f1[n - r]);
}

void logic() {  
    int n; cin >> n;
    cout << mul(nPr(2 * n, n), mis[n]) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    mis[1] = 1;
    for (int i = 2; i <= N; ++i) {
        mis[i] = mul(mis[i - 1], 2);
    }
    init();
    int t; cin >> t;
    while (t--) {
        logic();
    }

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/

















