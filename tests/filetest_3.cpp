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
#define task "EBOLA"

using namespace std;
const int N = 1e5 + 5;

int n, k;
vector<int> adj[N];
bool visited[N];
vector<int> f;

void dfs(int u) {
    visited[u] = true;
    f.pb(u);
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int m; cin >> m;
        while (m--) {
            int x; cin >> x;
            adj[i].pb(x);
        }
    }

    dfs(k);
    sort(all(f));
    cout << f.size() << '\n';
    for (auto x : f) {
        cout << x << ' ';
    }
    // execute;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    logic();
    return 0;
}