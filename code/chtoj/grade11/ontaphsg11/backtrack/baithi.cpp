
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

#define task ""


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

int n, m;
int a[N], p[N], S[N];
int ans = inf;

void q (int i = 1, int s = 0, int pre = -1, int cnt = 0){
    if (i > n || cnt >= m){
        ans = max(ans, s);
    }
    else{
        if (cnt + 1 <= m)
            ql(i + 1, s + a[i], 1, cnt + 1);
        ql(i + 1, s, 0, cnt);
    }
}

void logic() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    ql();
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
