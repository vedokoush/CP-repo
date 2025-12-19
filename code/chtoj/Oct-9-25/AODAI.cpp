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
#define task "AODAI"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int cnt[5];
int ans = 0;

void logic() {
    cin >> n;
    ms(cnt, 0);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    ans += cnt[4];
    while (cnt[1] > 0 and cnt[3] > 0) {
        ans++;
        cnt[1]--;
        cnt[3]--;
    }
    if (cnt[3] > 0) {
        ans += cnt[3];
        cnt[3] = 0;
    }
    ans += cnt[2] / 2;
    if (cnt[2] % 2 == 1) {
        ans++;
        if (cnt[1] > 2) {
            cnt[1] -= 2;
        } else {
            cnt[1] = 0;
        }
    }
    if (cnt[1] > 0) {
        ans += cnt[1] / 4;
        if (cnt[1] % 4 != 0) ans++;
    }
    cout << ans;
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

    // execute
    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/
