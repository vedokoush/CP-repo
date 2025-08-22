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
const int N = 1e3 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int a[N][N];
int dpl[N][N], dpr[N][N];
int up1[N][N], up2[N][N];
int down1[N][N], down2[N][N];

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            up1[i][j] = up1[i - 1][j - 1] + a[i][j];
            up2[i][j] = up2[i - 1][j + 1] + a[i][j];
        }
    }

    for (int i = m; i >= 1; --i) {
        for (int j = n; j >= 1; --j) {
            down1[i][j] = down1[i + 1][j + 1] + a[i][j];
            down2[i][j] = down2[i + 1][j - 1] + a[i][j];
        }
    }



    int ans = -inf;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            ans = max(ans, ((up1[i][j] + down1[i][j] - a[i][j]) + (up2[i][j] + down2[i][j] - a[i][j]) - a[i][j]));
        }
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

    logic();

    return 0;
}

/*
--/shouko\--
DRAFT:


------------
*/