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
#define task "Net2line"


using namespace std;
const int N = 1e5 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<iii> edge;
int n, m;
int par[N];
int ans = 0;
int cnt;

int acs(int u) {
    if (par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        par[x] = y;
    }
}



void sub2() {
    for (auto e : edge) {
        int u = e.se.fi;
        int v = e.se.se;
        int w = e.fi;

        if (acs(u) != acs(v)) {
            join(u, v);
            ans += w;
        }

    }
    cout << ans << '\n';
}

void logic() {
    cnt = 0;
    ans = 0;
    ms(par, 0);
    edge.clear();
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int w; cin >> w;
        if (!(w & 1)) ++cnt;
        edge.pb({w, {i, i + 1}});
    }
    for (int i = n + 1; i < 2 * n; ++i) {
        int w; cin >> w;
        if (!(w & 1)) ++cnt;
        edge.pb({w, {i, i + 1}});
    }
    for (int i = 1; i <= n; ++i) {
        int w; cin >> w;
        if (!(w & 1)) ++cnt;
        edge.pb({w, {i, i + n}});
    }
    sort (edge.begin(), edge.end());

    for (int i = 1; i <= 2 * n; ++i) {
        par[i] = i;
    }
    sub2();

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
