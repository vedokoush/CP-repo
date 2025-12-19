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
#define task "PEACH"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }
int n, a, b;
ii ar[N];
int ans;
priority_queue<int> pq;

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) {
        cin >> ar[i].fi >> ar[i].se;
    }
    int t = 1;

    sort (ar + 1, ar + n + 1);

    if (a < b - n)  a = b - n;

    for (int i = a; i <= b - 1; ++i) {
        while (ar[t].fi <= i) {
            pq.push(ar[t].se);
            // cout << pq.top() << '\n';
            ++t;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
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
