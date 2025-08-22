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
#define task "UCLN2"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};


int n, q, maxx = 0;
vector<int> a(N);
vector<ii> st(M);
vector<vector<int>> tmp(N);

void logic() {
    cin >> n >> q;
    maxx = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y;
        st[i] = {x, y};
        maxx = max(maxx, y);
    }
    for (int i = 1; i <= maxx; ++i) {
        for (int j = i; j <= maxx; j += i) {
            tmp[j].pb(i);
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int g = __gcd(a[i], a[j]);
            for (int d : tmp[g]) {
                int vi = a[i] / d;
                int vj = a[j] / d;
                sum = (sum + (vi * vj) % mod) % mod;
            }
        }
    }
    if (sum < 0) sum += mod;
    cout << sum << '\n';

    for (int i = 0; i < q; ++i) {
        int pos = st[i].fi;
        int y = st[i].se;
        a[pos] = y;

        sum = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int g = __gcd(a[i], a[j]);
                for (int d : tmp[g]) {
                    int vi = a[i] / d;
                    int vj = a[j] / d;
                    sum = (sum + (vi * vj) % mod) % mod;
                }
            }
        }
        if (sum < 0) sum += mod;
        cout << sum << '\n';
    }
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
