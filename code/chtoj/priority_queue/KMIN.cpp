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
#define task "KMIN"

using namespace std;
const int N = 5e4 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

priority_queue<iii, vector<iii>, greater<iii>> pq;
int n, m, k;
int a[N], b[N];

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
    }
    sort (a + 1, a + n + 1);
    sort (b + 1, b + m + 1);
    for (int i = 1; i <= n; ++i) {
        pq.push({a[i] + b[1], {i, 1}});
    }
    for (int i = 1; i <= k; ++i) {
        cout << pq.top().fi << '\n';
        int p1 = pq.top().se.fi;
        int p2 = pq.top().se.se;
        pq.pop();

        if (p2 < m) {
            pq.push({a[p1] + b[p2 + 1], {p1, p2 + 1}});
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