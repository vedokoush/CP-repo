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
#define task "TEAMS"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[N];
stack<int> s;
ii c[N];
bool check[N];
vector<ii> vt[N];
    int cnt = 1;


void sab() {
    ms(check, false);
    sort(c + 1, c + n + 1, greater<ii>());
    for (int i = 1; i <= n; ++i) {
        // cout << c[i].fi << ' ' << c[i].se << '\n';
    }
    int size = c[1].fi - 1;
    vt[cnt].pb({c[1].fi, c[1].se});
    for (int i = 2; i <= n; ++i) {
        if (size > 0) {
            vt[cnt].pb({c[i].fi, c[i].se});
            size--;
        }
        else {
            size = a[i];
            ++cnt;
            vt[cnt].pb({c[i].fi, c[i].se});
        }
    }
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        c[i].fi = a[i];
        c[i].se = i;
    }
    sab();
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; ++i) {
        cout<<vt[i].size()<<" ";
        for(auto x:vt[i]) cout<<x.se<<" ";
        cout << '\n';
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

/*
--/shouko\--
DRAFT:


------------
*/
