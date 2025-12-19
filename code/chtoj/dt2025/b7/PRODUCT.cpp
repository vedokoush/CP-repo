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
#define task "PRODUCT"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 123456789;

int n, k;
int a[N];
int ans = 1;
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

void logic() {
    cin >> n >> k;
    vector<int> pos, neg;
    vector<int> s;
    ans = 1;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (k == n) {
        for (int i = 1; i <= n; ++i) {
            ans = mul(ans, a[i]);
        }
        cout << (ans + mod) % mod;
        return;
    }

    if (a[n] <= 0 and k & 1) {
        for (int i = n; i >= n - k + 1; --i) {
            ans = (ans * a[i]) % mod;
        }
        cout << (ans + mod) % mod;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] >= 0) {
            pos.pb(a[i]);
        }
        else neg.pb(a[i]);
    }
    reverse(all(neg));

    if (k % 2 == 1) {
        s.pb(pos.back());
        pos.pop_back();
        k--;
    }

    while (k != 0) {
        int x = -inf, y = -inf;
        if (pos.size() >= 2) x = pos[pos.size()-1] * pos[pos.size()-2];
        if (neg.size() >= 2) y = neg[0] * neg[1];

        if (x > y) {
            s.pb(pos[pos.size() - 1]);
            s.pb(pos[pos.size() - 2]);
            pos.pop_back(); 
            pos.pop_back();
        } else {
            s.pb(neg[0]);
            s.pb(neg[1]);
            neg.erase(neg.begin(), neg.begin() + 2);
        }
        k -= 2;
    }
    for (int x : s) {
        ans = mul(ans, x);
    }
    cout << (ans + mod) % mod << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int t; cin >> t;
    while (t--) {
        logic();
    }
    return 0;
}