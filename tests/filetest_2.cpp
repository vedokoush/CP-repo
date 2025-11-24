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
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

string s;
int cnt;
int f[N];
int ans = inf;

void logic() {
    cin >> s;
    int l = 0;
    for (int r = 0; r < (int)s.size(); ++r) {
        int id = s[r] - 'A';
        if (!f[id]) ++cnt;
        ++f[id];

        while (cnt == 26) {
            ans = min(ans, r - l + 1);
            int q = s[l] - 'A';
            --f[q];
            if (f[q] == 0) --cnt;
            ++l;
        }
    }
    cout << (ans == inf ? -1 : ans);
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