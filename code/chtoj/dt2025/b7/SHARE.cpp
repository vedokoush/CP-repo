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
#define task "SHARE"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int limit;
ii a[N];
int b[N];

bool check(int mid) {
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].se > mid)
            s += mid;
        else
            s += a[i].se;
    }
    return s >= m;
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].se;
        a[i].fi = i;
        limit = max(a[i].se, limit);
    }
    int l = 1, r = limit;
    int res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            res = mid;
        }
        else {
            l = mid + 1;
        }
    }
    if (res == -1) {
        cout << -1;
        return;
    }
    sort(a + 1, a + n + 1);
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].se > res) {
            a[i].se = res;
            b[a[i].fi] = a[i].se;
            s += res;
        }
        else {
            b[a[i].fi] = a[i].se;
            s += a[i].se;
        }
    }
    if (s > m) {
        for (int i = 1; i <= n; i++) {
            a[i].se--;
            b[a[i].fi] = a[i].se;
            s--;
            if (s == m) {
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << ' ';
    }

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
