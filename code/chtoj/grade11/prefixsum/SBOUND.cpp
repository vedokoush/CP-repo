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
#define On(mask, pos) (mask | (1LL << pos))
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

int n, l, r;
int a[N];
int pre[N];
int ans;

void logic() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    sort (pre, pre + n + 1);    
    for (int j = 0; j <= n; ++j) {
        int L = lower_bound(pre, pre + j, pre[j] - r) - pre;
        int R = upper_bound(pre, pre + j, pre[j] - l) - pre;
        ans += (R - L);
    }
    cout << ans;

    // l <= pre[i] - pre[j] <= r
    // pre[j] - r <= pre[i] <= pre[j] - l

    // multiset<long long> s;
    // s.insert(0);

    // for (int j = 1; j <= n; j++) {
    //     ans += distance(
    //         s.lower_bound(pre[j] - r),
    //         s.upper_bound(pre[j] - l)
    //     );
    //     ans += distance(
    //         s.lower_bound(pre[j] + l),
    //         s.upper_bound(pre[j] + r)
    //     );
    //     s.insert(pre[j]);
    // }
    // cout << ans;
    // execute
}


/*

l <= abs(pre[j] - pre[i]) <= r

th1: l <= pre[j] - pre[i] <= r
-> pre[i] >= pre[j] - r
-> pre[i] <= pre[j] - l

th2: -l <= pre[j] - pre[i] <= -r
-> pre[i] <= pre[j] + r
-> pre[i] >= pre[j] + l

*/

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
