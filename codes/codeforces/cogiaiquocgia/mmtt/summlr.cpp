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
#define task ""

using namespace std;
const int N = 3e6 + 9;
const int inf = 1e18;
int n, l, r;
deque<int> dq;
int res = -inf;
int a[N];
int pref[N];

void logic() {
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = l; i <= n; ++i) {
        int L = max(0LL, i - r);
        int R = i - l;
        while (!dq.empty() and dq.front() < L) {
            dq.pop_front();
        }
        if (R >= L) {
            while (!dq.empty() and pref[dq.back()] >= pref[R]) {
                dq.pop_back();
            }
            dq.pb(R);
        }

        if (!dq.empty()) {
            res = max(res, pref[i] - pref[dq.front()]);
        }
    }
    cout << res << '\n';
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
DRAFT:

9 2 3
40 -40 0 3 -5 0 3 0 1

40 -40 0 = 0
-40 0 3 = -37
0 3 -5 = -2
3 -5 0 = -2
-5 0 3 = -2
0 3 0 = 3
3 0 1 = 4

dq: -40 0 3
cnt | 2 | 3 | 
cnt: 1 2 3
max: 0 


------------
*/
