#include <bits/stdc++.h>
#define int long long
#define task ""
using namespace std;
const int N = 1e6 + 9;
int n, k, h[N], f[N];
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    f[1] = 0;
    for (int i = 2; i <= n; ++i) {
        f[i] = 1e18;
        for (int j = i - k; j <= i - 1; ++j) {
            if (j >= 1) 
                f[i] = min(f[i], f[j] + abs(h[j] - h[i]));
        }
    }
    cout << f[n];
}
signed main(){
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(fopen(task ".inp", "r"))
        {
            freopen(task ".inp", "r", stdin);
            freopen(task ".out", "w", stdout);
        }
    }
    solve();
}
