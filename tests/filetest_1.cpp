#include <bits/stdc++.h>
using namespace std;
#define int long long
#define task "SPNUM"
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))

bool prime[1000006];

void sieve(int n){
    ms(prime, true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=n; i++)
        if(prime[i])
            for(int j=i*i; j<=n; j+=i)
                prime[j] = false;
}

void logic(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k; cin >> n >> k;
    sieve(n);
    
    int ans = 0;
    for(int i=2; i<=n; i++)
        if(prime[i] && __builtin_popcount(i) == k)
            ans++;
    
    cout << ans;
}

int32_t main(){
    #ifdef LOCAL
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    #endif
    logic();
}