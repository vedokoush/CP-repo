#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;

int t, n;
int a[N], minn[N];
string s;

void init() {
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        a[i] = inf;
        minn[i] = inf;
    }
}

namespace subtask1 {
    bool check() { return true; }

    void solve() {
        for (int k = 1; k <= n; ++k) {
            for (int j = k; j <= n; j += k) {
                if (s[j - 1] == '1') {
                    a[k] = j;
                    break;
                }
            }
            if (a[k] == inf) a[k] = n + 1;
        }

        for (int k = 1; k <= n; ++k) {
            for (int j = k; j < a[k]; j += k) {
                if (s[j - 1] == '0') {
                    minn[j] = min(minn[j], k);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == '0') ans += minn[i];
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        init();
        if (subtask1::check()) subtask1::solve();
    }
}