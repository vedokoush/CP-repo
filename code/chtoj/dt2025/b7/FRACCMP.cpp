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
#define task "FRACCMP"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e9;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int a, b, c, d;

__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void print(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

bool cmp(__int128 x, __int128 y) { 
    return x > y; 
}

bool eq(__int128 x, __int128 y) {
    return x == y;
}

void smol() {
    cin >> a >> b >> c >> d;
    if (a * d == b * c) {
        cout << 0 << '\n';
    }
    else if (a * d > b * c) {
        cout << 1 << '\n';
    }
    else {
        cout << -1 << '\n';
    }
}

void bigN() {
    __int128 a, b, c, d;
    a = read(), b = read(), c = read(), d = read();
    if (eq(a * c, b * d)) {
        cout << 0 << '\n';
    }
    else {
        if (cmp(a * c, b * d)) {
            cout << 1 << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }

}


void logic() {
    if (a <= M and b <= M and c <= M and d <= M) {
        smol();
    }
    else {
        bigN();
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

    int t; cin >> t;
    while (t--) {
        logic();
    }

    return 0;
}

/*
--/shouko\--
DRAFT:  

------------
*/
