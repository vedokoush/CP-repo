#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ms(d, x) memset(d, x, sizeof(d))

const int N = 1'000'000;
vector<int> fact(N + 1);

int modpow(int a, int e) {
    int r = 1;
    while (e) {
        if (e & 1) r = r * a;
        a = a * a;
        e >>= 1;
    }
    return r;
}

int nCr(int n, int k) {
    if (k < 0 || k > n || n > N) return 0;
    return fact[n] / (fact[k] * fact[n - k]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    return 0;
}