#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << '\n';
#define shouko 1
#define orz shouko
#define task ""

using namespace std;
const int MAXN = 1000000 + 9; // safe upper bound
const int MAXM = 1000000 + 9;

int n, m, q;
int xarr[MAXN];
int S[MAXM];       // S[i] = ±1
long long T[MAXM]; // T[i] shift

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if(!(cin >> n >> m >> q)) return 0;

    for(int i = 1; i <= n; ++i) {
        cin >> xarr[i];
    }

    vector<long long> k(m+1);
    for(int i = 1; i <= m; ++i) cin >> k[i];


    S[0] = 1;
    T[0] = 0;

    for(int i = 1; i <= m; ++i){
        S[i] = -S[i-1];
        T[i] = -T[i-1] + 2LL * k[i];
    }


    while(q--){
        int id, K;
        cin >> id >> K;

        long long ans = (long long)S[K] * xarr[id] + T[K];
        cout << ans << '\n';
    }

    return 0;
}