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
#define task "LISTMAN"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

int n, q;
int a[N];
int tree[4 * N];

void update(int id, int l, int r, int pos, int val) {
    if (pos < l or pos > r) {
        return;
    }
    if (l == r) {
        tree[id] = val;
        return;
    }
    int mid = l + r >> 1;
    update (id * 2, l, mid, pos , val);
    update (id * 2 + 1, mid + 1, r, pos, val);
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r or v < l) {
        return inf;
    }
    if (l >= u and r <= v) {
        return tree[id];
    }
    int mid = (l + r) / 2;
    return min(get(2 * id, l, mid, u, v),
               get(2 * id + 1, mid + 1, r , u, v));
} 

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] <= 0) {
            a[i] = inf;
        }
        update(1, 1, n, i, a[i]);
    }
    while (q--) {
        char c; cin >> c;
        if (c == 'S') {
            int pos, val; cin >> pos >> val;
            if (val <= 0) {
                val = inf;
            }
            update(1, 1, n, pos, val);
        }
        else {
            int x = get(1, 1, n, 1, n);
            if (x == inf) {
                cout << 0;
            }
            else cout << x;
            cout << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    solve();

    // execute;
    return 0;
}
  
/* shouko */