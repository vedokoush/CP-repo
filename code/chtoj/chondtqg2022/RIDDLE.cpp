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
#define task "RIDDLE"

using namespace std;
const int N = 1e6 + 9;
const int M = 25;
const int inf = 1e18;
const int mod = 1e9 + 7;

int m, n;
int a[M], b[N];
vector<int> s;

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    int t = 1LL << m;

    for (int i = 0; i < t; ++i) {
        int sum = 0, x = i;
        for (int j = 1; j <= m; ++j) {
            int d = x % 2;
            x /= 2;
            if (d) sum += a[j];
        }
        s.pb(sum);
    }

    sort(all(s));
    s.erase(unique(all(s)), s.end());

    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        int ans = (binary_search(all(s), b[i]) ? 1 : 0);
        cout << ans;
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
