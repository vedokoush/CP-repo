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

#define task "SOCOLA"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int base = 311;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int n, k;
int ans = -1;
int r;
int cnt;
int a[N];

bool check(int x) {
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += a[i] / x;
        if (cnt >= k) return true;
    }
    return cnt >= k;
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    r = *max_element(a + 1, a + n + 1);
    int l = 1;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
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
