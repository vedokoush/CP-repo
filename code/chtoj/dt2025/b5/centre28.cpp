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
#define task "CENTRE28"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int dist[N];
vector<ii> adj[N];
bool check[N];
int dist1[N], dist2[N];
int ways1[N], ways2[N];
vector<int> ans;
priority_queue<ii, vector<ii>, greater<ii>> pq;
int cnt;
int ways[N];

void dijk(int start, int dist[], int ways[]) {
    for (int i = 1; i <= n; ++i) {
        dist[i] = inf;
        ways[i] = 0;
    }

    dist[start] = 0;
    ways[start] = 1;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().fi;
        int u = pq.top().se;
        pq.pop();

        if (cost > dist[u]) continue;

        for (auto e : adj[u]) {
            int v = e.fi;
            int c = e.se;
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                ways[v] = ways[u];
                pq.push({dist[v], v});
            } else if (dist[v] == dist[u] + c) {
                ways[v] += ways[u];
            }
        }
    }
}

void logic() {
    ms(check, false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dijk(1, dist1, ways1);
    dijk(n, dist2, ways2);
    
    int sp = dist1[n];
    for (int v = 2; v < n; ++v) {
        if (dist1[v] + dist2[v] != sp || ways1[v] * ways2[v] < ways1[n]) {
            ans.pb(v);
        }
    }
    
    cout << ans.size() << '\n';
    for (auto x : ans) {
        cout << x << '\n';
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
