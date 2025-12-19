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

string a, b;
int n, m;
int ans = inf;

int ct(const string &s, const string &pat) {
    if (pat.empty()) return 0;
    int cnt = 0;
    size_t pos = 0;
    while (true) {
        pos = s.find(pat, pos);
        if (pos == string::npos) break;
        ++cnt;
        pos = pos + 1;
    }
    return cnt;
}

void logic() {
    cin >> a >> b;
    n = a.size();
    m = b.size();
    for (int c = 1; c <= min(n, m); ++c) {
        for (int i = 0; i <= n - c; ++i) {
            string x = a.substr(i, c);
            if (ct(a, x) == 1 and ct(b, x) == 1) {
                ans = min(ans, c);
            }
        }
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
