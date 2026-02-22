#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a), _b=(b); i<=_b; i++)
#define REP(i,n) for(int i=0,_n=(n); i<_n; i++)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define int long long
#define task ""

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

template<class X, class Y>
bool minimize(X &x, const Y &y) {
    if (x > y) { x = y; return true; }
    return false;
}

const int N = 1e6 + 9;
const int inf = 1e18;

int n, k;
int a[N];
int pre[N];
int ans = inf;
int pos;

void init(void) {
    cin >> n >> k;
    FOR(i, 1, n) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
}

namespace shouko {
    bool check(void) { return true; }
    void solve(void) {
        FOR(i, k, n) {
            if (pre[i] - pre[i - k] < ans) {
                ans = pre[i] - pre[i - k];
                pos = i - k + 1;
            }
        }
        cout << pos;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    init();
    if (shouko::check()) return shouko::solve(), 0;

    return 0;
}
