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
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int m, n, p;
int i = 0;
vector<ii> at, bt, ct;
int minn = inf;
bool taken[N];

void st1() {
    // sort(all(at));
    // sort(all(bt));
    // sort(all(ct));
    for (auto x : at) {
        // cout << x.fi << ' ';
        if (x.fi <= minn) {
            minn = x.fi;
            taken[x.se] = true;
        }
    }
    cout << '\n';
    for (auto x : bt) {
        cout << x.fi << ' ';
    }
    cout << '\n';
    for (auto x : ct) {
        cout << x.fi << ' ';
    }
    cout << '\n';

}

void logic() {
    cin >> m >> n >> p;
    int k = m + n + p;
    while (k--) {
        int a, b, c; cin >> a >> b >> c;
        ++i;
        at.pb({a, i});
        bt.pb({b, i});
        ct.pb({c, i});
    }
    st1();
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
