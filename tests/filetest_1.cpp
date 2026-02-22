#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 3;
const int inf = 1e18;

int n;
int a[N][N];
pair<int, int> start;
int dist[N][N];
queue<pair<int, int>> q;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void init(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    start = {1, 1};
}

namespace subtask {
    bool check() { return true; }
    bool bfs(int d) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = inf;
            }
        }
        dist[start.first][start.second] = 0;
        q.push({start.first, start.second});
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i <= 3; ++i) {
                int u = x + dx[i];
                int v = y + dy[i];
                if (u >= 1 and u <= n and v >= 1 and v <= n and (abs(a[x][y] - a[u][v]) <= d)) {
                    if (dist[u][v] > dist[x][y] + 1) {
                        dist[u][v] = dist[x][y] + 1;
                        q.push({u, v});
                    }
                }
            }
        }
        return dist[n][n] != inf;
    }
    void solve() {
        int l = 1, r = inf, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (bfs(mid) and dist[n][n] != inf) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        cout << ans;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    if (subtask::check()) subtask::solve();
}

/*

1
2 3
4 5 6
7 8 9 10


*/