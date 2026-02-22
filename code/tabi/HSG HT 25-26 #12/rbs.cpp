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
int n; 
string s;
int ans = 0;
bool taken[N];

void init(void) {
    memset(taken, false, sizeof(taken));
    ans = 0;
    s = "";
    cin >> n;
    cin >> s;
}

namespace shouko {
    bool check(void) { return true; }
    void solve(void) {
        s = ' ' + s;
        for (int i = 2; i <= n; i += 2) {
            // cout << s[i] << ' '; 
            if (!taken[i]) {
                if (s[i] == ')') {
                    ++ans;
                    taken[i] = true;
                }
                if (s[i] == '(') {
                    ans += 4;
                    taken[i] = true;
                    taken[i + 2] = true;
                }
            }
        }
        cout << ans << '\n';
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

    int t; cin >> t;
    while(t--) {
    init();
    if (shouko::check()) shouko::solve();
    }

    return 0;
}