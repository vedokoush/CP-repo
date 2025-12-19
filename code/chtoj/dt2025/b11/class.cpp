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
#define task "class"

using namespace std;
const int N = 1e6 + 9;
const int mod = 1e9 + 7;

int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int subm(int a, int b) {return ((a - b) % mod + mod) % mod;}

int x[N], y[N], a[N], prefG[N];

int binpow(int a, int n){
    if (n == 0) return 1;
    int res = binpow(a, n / 2);
    res = mul(res, res);
    if (n & 1) res = mul(res, a);
    return res;
}

int inv(int a){ return binpow(a, mod - 2); }

void solve(){
    int n, k, x1, y1, C, D, E1, E2, F;
    cin >> n >> k >> x1 >> y1 >> C >> D >> E1 >> E2 >> F;

    x[1] = x1; y[1] = y1;
    for(int i = 2; i <= n; ++i){
        x[i] = ( (C * x[i-1]) % F + (D * y[i-1]) % F + E1 ) % F;
        y[i] = ( (D * x[i-1]) % F + (C * y[i-1]) % F + E2 ) % F; 
    }
    for(int i = 1; i <= n; ++i){
        a[i] = (x[i] + y[i]) % F;
    }

    prefG[0] = 0;
    for(int t = 1; t <= n; ++t){
        int G;
        if(t == 1){
            G = k % mod;
        }else{
            int num = subm(binpow(t % mod, k + 1), t % mod);
            G = mul(num, inv((t - 1) % mod));
        }
        prefG[t] = add(prefG[t-1], G);
    }

    int ans = 0;
    for(int idx = 1; idx <= n; ++idx){
        int mult = (n - idx + 1) % mod;     
        ans = add(ans, mul(mul(a[idx] % mod, mult), prefG[idx]));
    }

    cout << ans % mod << '\n';
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
        solve();
    }

    return 0;
}