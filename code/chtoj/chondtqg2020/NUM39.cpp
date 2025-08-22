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
#define task "NUM39"

using namespace std;
const int N = 333333;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

vector<int> p; 
vector<int> ans;
bool prime[N + 5];

void sieve() {
    ms(prime, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j += i) {
                prime[j] = false; 
            }
        }
    }
    for (int i = 2; i <= N; ++i) {
        if (prime[i]) {
            p.pb(i);
        }
    }
}

void logic() {
    sieve();
    ans.pb(6561);
    for (auto x : p) {
        if (x == 3) continue;
        int val = 9 * x * x;
        if (val <= (int)1e12) ans.pb(val);
    }
    sort(all(ans));

    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        auto L = lower_bound(all(ans), l);
        auto R = upper_bound(all(ans), r);
        cout << (R - L) << '\n';
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

    logic();
    return 0;
}

/*
--/shouko\--
DRAFT:
------------
*/