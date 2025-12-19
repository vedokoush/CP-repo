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
#define task "ROAD"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k, x;
vector<ii> xe[N], xer[N], bo[N];
int distx[N], distb[N], distxr[N];

void dijk(int start, vector<ii> adj[], int dist[]) {
    for(int i = 1; i <= n; i++) dist[i] = inf;
    dist[start] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int u = pq.top().se;
        int cost = pq.top().fi;
        pq.pop();
        
        if(cost > dist[u]) continue;
        
        for(auto edge : adj[u]) {
            int v = edge.se;
            int w = edge.fi;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void logic() {
    cin >> n >> m >> k >> x;
    for(int i = 1; i <= m; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        xe[u].push_back({b, v});
        bo[v].push_back({a, u});
        xer[v].push_back({b, u});
    }
    
    dijk(1, xe, distx);
    dijk(k, bo, distb);
    dijk(n, xer, distxr);
    
    int res = inf;
    
    for(int i = 1; i <= n; i++) {
        if(distx[i] + distb[i] <= x) {
            res = min(res, distx[i] + distxr[i]);
        }
    }
    
    dijk(1, bo, distb);
    if(distb[k] <= x) {
        res = min(res, distb[k] + distxr[k]);
    }
    
    cout << (res == inf ? -1 : res) << '\n';
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