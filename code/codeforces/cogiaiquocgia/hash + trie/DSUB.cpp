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
const int mod = 2e9 + 11;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}
int base[N];
int pre[N];
int n, k; 
string a; 

int getHash(int l, int r) {
    if (l > r) return -1;
    return sub(pre[r], mul(pre[l - 1], base[r - l + 1]));
}

bool check(int len) {
    vector<int> v;
    int cnt = 1;
    for (int r = len; r <= n; ++r) {
        int l = r - len + 1;
        int H = getHash(l, r);
        v.pb(H);
    }
    sort(all(v));
    for (int i = 1; i < v.size(); ++i) {
        if (v[i - 1] != v[i]) {
            cnt = 1;
        }
        else {
            ++cnt;
        }
        if (cnt >= k) {
            return true;
        }
    }
    return false;
}

void logic() {
    cin >> n >> k;
    cin >> a;
    a = ' ' + a;

    base[0] = 1;
    for (int i = 1; i <= n; ++i) {
        base[i] = mul(base[i - 1], 256);
    }

    for (int i = 1; i <= n; ++i) {
        pre[i] = add(mul(pre[i - 1], 256), a[i]);
    }

    int l = 1, r = n, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid + 1;
            ans = mid;
        }
        else {
            r = mid - 1;
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
