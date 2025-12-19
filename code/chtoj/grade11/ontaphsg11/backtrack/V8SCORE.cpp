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
\       /|  | |  |   `'  '-'  '('  '-'(_.-' |  |\   \    `'  '-'  '
 `-----' `--' `--'     `-----'   `-----'    `--' '--'      `-----'
*/

#define task "V8SCORE"


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
int n, m, k;
int f[N][N];
int a[N][N];
int sum;
vector<int> ans;

void ql(int i, int p, int sum) {
    if (sum > k) return;

    if (i > m) {
        if (sum == k) {
            cout << "YES\n";
            for (int x : ans) cout << x << ' ';
            exit(0);
        }
        return;
    }

    for (int j = 1; j <= n; ++j) {
        if (i > 1 && p != 0) {
            if (a[j][i] < a[p][i - 1]) continue;
        }

        if (j > 1 && a[j][i] < a[j - 1][i]) continue;

        ans.push_back(a[j][i]);
        ql(i + 1, j, sum + a[j][i]);
        ans.pop_back();
    }
}


void logic() {
    cin >> k >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            f[i][j] = 0;
        }
    }
    ql(1, 0, 0);
    cout << "NO";
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
