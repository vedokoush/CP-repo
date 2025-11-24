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
// dont copy my flow dude
#define task ""


using namespace std;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
int n, k, ans;
int a[N];
int cnt[N];

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int x = 500000;
    for (int i = 1; i <= n; ++i) {
        int id = k - a[i] * a[i];
        if (0 <= id + x and id + x < N) ans += cnt[id + x];
        if (0 <= a[i] + x and a[i] + x < N) cnt[a[i] + x]++;
    }
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
    
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/
