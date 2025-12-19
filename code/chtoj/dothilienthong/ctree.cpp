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
#define task "CTREE"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;

int n;
int dist1[N], dist2[N], par[N];
vector<int> adj[N];
int far1, far2;
int max_dist = -1;

void bfs1(int start) {
    fill(dist1 + 1, dist1 + n + 1, inf);
    fill(par + 1, par + n + 1, -1);
    queue<int> q;
    dist1[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist1[v] > dist1[u] + 1) {
                dist1[v] = dist1[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void bfs2(int start) {
    fill(dist2 + 1, dist2 + n + 1, inf);
    fill(par + 1, par + n + 1, -1);
    queue<int> q;
    dist2[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist2[v] > dist2[u] + 1) {
                dist2[v] = dist2[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    bfs1(1);
    max_dist = -1;
    for (int i = 1; i <= n; ++i) {
        if (dist1[i] > max_dist) {
            max_dist = dist1[i];
            far1 = i;
        }
    }

    bfs2(far1);
    max_dist = -1;
    for (int i = 1; i <= n; ++i) {
        if (dist2[i] > max_dist) {
            max_dist = dist2[i];
            far2 = i;
        }
    }

    vector<int> path;
    int cur = far2;
    while (cur != -1) {
        path.pb(cur);
        cur = par[cur];
    }
    reverse(all(path));

    int len = path.size();
    if (len & 1) {
        cout << "1\n";
        cout << path[len/2] << '\n';
    } else {
        cout << "2\n";
        if (path[len/2 - 1] > path[len/2]) {
            cout << path[len/2] << ' ' << path[len/2 - 1] << '\n';
        } else {
            cout << path[len/2 - 1] << ' ' << path[len/2] << '\n';
        }
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

    logic();
    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/