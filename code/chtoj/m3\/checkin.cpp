#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define task "CHECKIN"
using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;

int n, m;
int k;
vector<iii> edge;
int par[N];
int ans;
int x[N];
int tmp;

int acs(int u) {
    if (par[u] == u) return u;
    return par[u] = acs(par[u]);
}

void join(int u, int v) {
    u = acs(u);
    v = acs(v);
    if (u != v) par[u] = v;
}

void sub2() {
    for (auto x : edge) {
        int c = x.fi;
        int u = x.se.fi;
        int v = x.se.se;
        if (acs(u) != acs(v)) {
                ++tmp;
            join(u, v);
            ans += c;
        }
    }
    if (tmp == n - 1) cout << ans;
    else {
        cout << -1;
    }
}

void logic() {
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, c; cin >> u >> v >> c;
        edge.push_back({c, {u, v}});
    }
    sort(edge.begin(), edge.end());
    for (int u = 1; u <= n; ++u) {
        par[u] = u;
    }
    sub2();
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen(task ".inp", "r", stdin);
    freopen(task ".out", "w", stdout);

    logic();

    return 0;
}
