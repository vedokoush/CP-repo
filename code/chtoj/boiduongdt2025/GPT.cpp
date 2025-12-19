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
#define task "GPT"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int k, n;
int c;
int tmp = 0;
int pre[11];

int binpow(int a, int b) {
    int res = 1;
    a %= 10;
    while (b > 0) {
        if (b & 1)
            res = res * a % 10;
        a = a * a % 10;
        b >>= 1;
    }
    return res;
}

void logic() {
    cin >> k >> n;
    for (int i = 1; i <= 10; ++i) {
        c = binpow(i, (1LL << k));
        tmp = (tmp + c) % 10;
        pre[i] = (pre[i - 1] + c) % 10;
    }


    int ans = ((n / 10) * tmp % 10 + pre[n % 10]) % 10;
    cout << ans << '\n';

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

    logic();

    return 0;
}

