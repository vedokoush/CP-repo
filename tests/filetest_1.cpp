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
#define task "MST1"

using namespace std;

const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = (int)1e18;
const int mod = (int)1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int par[N], sz[N];
int n, m;
vector<iii> e; 
int taken;
int ans;

int acs(int u) {
    if (par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void mst(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i, sz[i] = 1;
    }
}

void join(int u, int v) {
    u = acs(u); v = acs(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

void logic() {
    cin >> n >> m;

    e.reserve(m);
    while (m--) {
        int u, v, w; 
        cin >> u >> v >> w;
        e.pb({w, {u, v}});
    }

    if (n <= 1) { 
        cout << 0 << '\n'; 
        return; 
    }
    if (m == 0) { 
        cout << "DISCONNECTED\n"; 
        return; 
    }

    sort(all(e));
    mst(n);

    int rm = n - 1;


    for (auto ed : e) {
        int w = ed.fi;
        int u = ed.se.fi;
        int v = ed.se.se;
        if (acs(u) != acs(v)) {
            join(u, v);
            ans += w;
            ++taken;
            if (taken == rm) break;
        }
    }

    if (taken != rm) cout << "DISCONNECTED\n";
    else cout << ans << '\n';

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

/*
--/shouko\--

------------
*/
