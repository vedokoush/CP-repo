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
#define task "SPECIAL"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 2e9 + 11;
const int base = 311;

inline int add(int a, int b, int mod) { return (a + b) % mod; }
inline int sub(int a, int b, int mod) { return ((a - b) % mod + mod) % mod; }
inline int mul(int a, int b, int mod) { return (1LL * a * b) % mod; }

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int x; 
int h[N];
int k;

void prime(int n) {
    k = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            // cout << i << " ";
            h[++k] = i;
            
            if (i != n / i) {
                // cout << n / i << " ";
                h[++k] = n / i;
            }
        }
    }
}

void solve() {
    cin >> x;
    prime(x);
    sort(h + 1, h + k + 1);
    int ct = 0;
    for (int i = 1; i <= k; ++i) {
        // cout << h[i] << ' ';
        if (h[i] + 1 == h[i + 1]) {
            cout << h[i] << ' ';
            ++ct;
        }
    }
    if (ct == 0) cout << -1;
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }

    int q; cin >> q;
    while (q--) {
        solve();
    }

    // execute;
    return 0;
}

/* shouko */
