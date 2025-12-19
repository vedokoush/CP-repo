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
cont int base = 256;
const int mod = 2e9 + 11;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}
int base[N];
int pre[N];

int getHash(int l, int r) {
    if (l > r) return -1;
    return sub(pre[r], mul(pre[l - 1], base[r - l + 1]));
}

void logic() {
    string a, b; cin >> a >> b;
    int n = a.size();
    int m = b.size();
    a = ' ' + a;
    b = ' ' + b;
    int H = 0;
    for (int i = 1; i <= m; ++i) {
        H = add(mul(H, 256), b[i]);
    }
    base[0] = 1;
    for (int i = 1; i <= max(n, m); ++i) {
        base[i] = mul(base[i - 1], 256);
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = add(mul(pre[i - 1], 256), a[i]);
    }
    for (int r = m; r <= n; ++r) {
        int l = r - m + 1;
        if (getHash(l, r) == H) {
            cout << l << ' ';
        }
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
