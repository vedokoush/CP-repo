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
#define task "factorial"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
string s;
int c[N];


void logic() {
    int n; cin >> n;
    cin >> s;
    s = " " + s;
    ms(c, 0);
    for (int i = 1; i < (int)s.size(); ++i) {
        int d = s[i] - '0';
        if (d == 2) c[2]++;
        else if (d == 3) c[3]++;
        else if (d == 4) { c[3]++; c[2] += 2; }
        else if (d == 5) c[5]++;
        else if (d == 6) { c[5]++; c[3]++; }
        else if (d == 7) c[7]++;
        else if (d == 8) { c[7]++; c[2] += 3; }
        else if (d == 9) { c[7]++; c[3] += 2; c[2]++; }
    }
    for (int i = 9; i >= 2; --i) {
        while (c[i]--) cout << i;
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

1234



1234
288

288/2=144
288/2=144/2=72/2=36/2=18/2=9/3=3/3=1

288/2=144
144/2=72
72/2=36
36/2=18
18/2=9
9/3=3
3/3=1



33222


------------
*/