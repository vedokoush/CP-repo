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
#define task "GAS"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int ans = 1;
int n, k;
deque<ii> dq;
int a[N];

void logic() {
    cin >> n >> k;
    k -= 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dq.push_front({a[1], 1});
    for (int i = 2; i <= n; ++i) {
        while (!dq.empty() and dq.back().fi > a[i]) {
            dq.pop_back();
        }
        dq.push_back({a[i], i});
        while (!dq.empty() and dq.front().se < max(1LL, i - k + 1)) {
            dq.pop_front();
        }
        ans += dq.front().fi;
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

/*
--/shouko\--
DRAFT:


------------
*/
