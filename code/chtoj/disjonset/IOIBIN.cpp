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
#define task "IOIBIN"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int n;
int par[N];
vector<int> adj[N];

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

void logic() {
    cin >> n;
    for (int i = 1; i <= 1e6; ++i) {
        par[i] = i;
    }
    while (n--) {
        int u, v, x; cin >> u >> v >> x;
        if (x == 1) {
            join(u, v);
        }
        else {
            if (acs(u) == acs(v)) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
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
