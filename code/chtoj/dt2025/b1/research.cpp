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
#define task "RESEARCH"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int par[N];
int n, m;
string s;
vector<int> v;
int cnt;

int acs(int u) {
    if (par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void join(int u, int v) {
    int x = acs(u);
    int y = acs(v);
    if (x != y) {
        par[y] = x;
    }
}

void logic() {
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
    while (m--) {
        int u,v; cin >> u >> v;
        if (s[u] == s[v]) {
            // cout << u << ' ' << v << '\n';
            join(u, v);
        }
    }
    for (int i = 1; i <= n; ++i) {
        v.pb(acs(i));
    }
    cout << '\n';
    sort(all(v));
    for (int i = 1; i < (int)v.size(); ++i) {
        // cout << v[i] << ' ';
        if (s[v[i]] != s[v[i - 1]]) {
            ++cnt;
        }
    }
    cout << -1;
    
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
