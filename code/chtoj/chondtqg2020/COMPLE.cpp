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
#define task "COMPLE"

using namespace std;
const int N = 1e3 + 5;
int n;
string a[N];
int c[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = ' ' + a[i];
    }

    ms(c, 0);

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (i != j && j != k && k != i) {
                    if (a[i][j] == '1' && a[j][k] == '1' && a[k][i] == '1') {
                        c[i] = c[j] = c[k] = 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) ans += c[i];
    cout << ans;
    // execute;
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