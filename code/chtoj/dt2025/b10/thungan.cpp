#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 9;
int n, m;
int lazy[4 * N], tree[4 * N];
int x;

void down(int id) {
    if (lazy[id]) {
        int v = lazy[id];
        lazy[id * 2] += v;
        tree[id * 2] += v;
        lazy[id * 2 + 1] += v;
        tree[id * 2 + 1] += v;
        lazy[id] = 0;
    }
}

// a[u -> v] += val
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int getPoint(int id, int l, int r, int pos) {
    if (l == r) return tree[id];
    down(id);
    int mid = (l + r) / 2;
    if (pos <= mid) return getPoint(id * 2, l, mid, pos);
    else return getPoint(id * 2 + 1, mid + 1, r, pos);
}

void solve() {
    cin >> n >> x;
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        char c; cin >> c;
        if (c == 'I') {
            int k; cin >> k;
            ++cur;
            update(1, 1, n, cur, cur, k);
        }
        else if (c == 'A') {
            int k; cin >> k;
            if (cur > 0) update(1, 1, n, 1, cur, k);
        }
        else if (c == 'S') {
            int k; cin >> k;
            if (cur > 0) update(1, 1, n, 1, cur, -k);
        }
        else if (c == 'F') {
            int k; cin >> k;
            if (cur < k) {
                cout << "-1\n";
                continue;
            }
            priority_queue<int, vector<int>, greater<int>> minH;
            for (int j = 1; j <= cur; ++j) {
                int val = getPoint(1, 1, n, j);
                if ((int)minH.size() < k) minH.push(val);
                else if (val > minH.top()) {
                    minH.pop();
                    minH.push(val);
                }
            }
            cout << minH.top() << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
