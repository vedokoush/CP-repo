#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define task ""
// dont copy my flow dude

using namespace std;

const int N = 1000058;
const int M = 100000;

vector<int> f[M + 1];
int a[N], cnt[N];

void logic() {
    int n, m; 
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= m; i++) cnt[i] = 0;

    int L = 1, cntcheck = 0;
    int ans = LLONG_MAX;

    for (int R = 1; R <= n; R++) {
        for (int x : f[a[R]]) {
            if (x > m) break;
            if (cnt[x] == 0) cntcheck++;
            cnt[x]++;
        }

        while (cntcheck == m) {
            ans = min(ans, a[R] - a[L]);
            for (int x : f[a[L]]) {
                if (x > m) break;
                cnt[x]--;
                if (cnt[x] == 0) cntcheck--;
            }
            L++;
        }
    }

    if (ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
    // execute;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    for (int i = 1; i <= M; i++) {
        for (int j = i; j <= M; j += i) {
            f[j].pb(i);
        }
    }

    int t; 
    cin >> t;
    while (t--) logic();
}