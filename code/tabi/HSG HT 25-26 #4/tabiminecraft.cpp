#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PEf_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task ""


using namespace std;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}



const int N = 505;

int t, n, m, k;
string s[N];
int pre[N][N];

int rubikcube(int x1, int y1, int x2, int y2) {
    x1 = max(1LL, x1);
    y1 = max(1LL, y1);
    x2 = min(n, x2);
    y2 = min(m, y2);
    if (x1 > x2 || y1 > y2) return 0;
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    int t = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (s[i][j] == 'g');
            if (s[i][j] == 'g') t++;
        }
    }

    int f = k - 1;
    int ans = inf;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (s[i][j] == '.') {
                int left = rubikcube(i - f, j - f, i + f, j + f);
                ans = min(ans, left);
            }
        }
    }

    if (ans == inf) ans = 0;

    cout << t - ans << '\n';
}


void logic() {
    cin >> t;
    while(t--) {
        solve();
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

/*
--/shouko\--
DfAFT:
------------
*/