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
#define task ""
using namespace std;

const int N = 1e6 + 9;
int a[N], n;
int sum;
int pref;
int cnt;
int ans;


void logic() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        sum += a[i];
    }
    if (sum % 3 != 0) {
        cout << 0;
        return;
    }
    int k = sum / 3;
    for (int i = 1; i <= n - 1; i++) {
        pref += a[i];
        if (pref == 2 * k) ans += cnt;
        if (pref == k) cnt++;
    }
    cout << ans;
    // execute;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    logic();
}