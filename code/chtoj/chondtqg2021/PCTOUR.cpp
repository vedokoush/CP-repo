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
#define task "PCTOUR"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct str{
    int x, y, l, w;
} a[N];

int n, m;
int c[N];
vector<ii> adj[N];

priority_queue<ii, vector<ii>, greater<>> pq;
int dist1[N], distn[N];

void dijk(int start, int dist[]) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf; 
    }
    dist[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int cost = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (cost != dist[u]) {
            continue;
        }
        for (auto e : adj[u]) {
            int v = e.fi;
            int c = e.se;
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

void sub1() {
    dijk(1, dist1);
    dijk(n, distn);

    int ans = inf;
    for (int i = 1; i <= n; i++) {
        if (dist1[i] >= inf || distn[i] >= inf) continue;
        ans = min(ans, dist1[i] + distn[i] + c[i]);
    }

    if (ans >= inf) cout << -1;
    else cout << ans; 
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    
    bool check = true;
    for (int i = 1; i <= m; i++) {
        int x, y, l, w;
        cin >> x >> y >> l >> w;

        if (l != w) check = false;
        else {
            adj[x].pb({y, w});
            adj[y].pb({x, w});
        }
        a[i] = {x, y, l, w};
    }
    if (check) sub1();
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