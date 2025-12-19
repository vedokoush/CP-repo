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

#define task "KSACK1"


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
ii a[N];
int ans;
int pre[N];
vector<int> pos, vt;


void ql(int i, int we, int va) {
    if (va + (pre[n] - pre[i - 1]) < ans) {
        return;
    }
    if (we > k) return;
    if (i > n) {
        if (we <= k) {
            if (va > ans) {
                ans = va;
                pos = vt;
            }
        }
    }
    else {
        if (we + a[i].fi <= k) {
            vt.pb(i);
            ql(i + 1, we + a[i].fi, va + a[i].se);
            vt.pop_back();
        }

        ql(i + 1, we, va);
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].fi >> a[i].se;
        pre[i] = pre[i - 1] + a[i].se;
    }
    ql(1, 0, 0);
    cout << ans << '\n';
    for (auto x : pos) {
        cout << x << ' ';
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
