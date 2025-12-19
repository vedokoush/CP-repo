#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define Is(mask, pos) (mask & (1LL << pos))
#define On(mask, pos) (mask  (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';

/*
  .-')    ('-. .-.                          .-. .-')
 ( OO ). ( OO )  /                          \  ( OO )
(_)---\_),--. ,--. .-'),-----.  ,--. ,--.   ,--. ,--.  .-'),-----.
/    _ | |  | |  |( OO'  .-.  ' |  | |  |   |  .'   / ( OO'  .-.  '
\  :` `. |   .|  |/   |  | |  | |  | | .-') |      /, /   |  | |  |
 '..`''.)|       |\_) |  |\|  | |  |_|( OO )|     ' _)\_) |  |\|  |
.-._)   \|  .-.  |  \ |  | |  | |  | | `-' /|  .   \    \ |  | |  |
\       /|  | |  |   `'  '-'  ' '  '-'(_.-' |  |\   \    `'  '-'  '
 `-----' `--' `--'     `-----'   `-----'    `--' '--'      `-----'
*/

#define task "FBIRD"


using namespace std;
const int N = 25;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int base = 311;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int n, m, w;
int a[N][N], maxx[N];
int res = -1;
bool stop;

void ql(int i, int prev, int sum) {
    if (stop) return;
    if (sum + maxx[i] < res || sum > w) return;
    if (i > n) {
        res = max(res, sum);
        if (res == w) {
            stop = true;
        }
        return;
    }
    for (int j = m; j >= 1; j--) {
        if (a[i][j] < prev) break;
        if (sum + a[i][j] * (n - i + 1) > w) continue;
        ql(i + 1, a[i][j], sum + a[i][j]);
    }
}

void logic() {
    cin >> m >> n >> w;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(a[i] + 1, a[i] + m + 1);
    }
    for (int i = n; i >= 1; i--) {
        maxx[i] = maxx[i + 1] + a[i][m];
    }
    ql(1, 0, 0);
    cout << res;
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

