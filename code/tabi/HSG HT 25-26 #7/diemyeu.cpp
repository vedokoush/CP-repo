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

int n;
int BIT[N];
int l[N], r[N];
int a[N], b[N];

void update(int x, int val) {
    for (; x <= n; x += x & -x) {
        BIT[x] += val;
    }
}

int query(int x) {
    int ans = 0;
    for (; x >= 1; x -= x & -x) {
        ans += BIT[x];
    }
    return ans;
}

void logic() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
    }

    for (int j = 1; j <= n; ++j) {
        l[j] = (j - 1) - query(a[j]);
        update(a[j], 1);
    }

    ms(BIT, 0);

    for (int j = n; j >= 1; --j) {
        r[j] = query(a[j] - 1);
        update(a[j], 1);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += l[i] * r[i];
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
