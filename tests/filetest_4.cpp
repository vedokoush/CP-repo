#include <bits/stdc++.h>
#define int long long
#define Rand(l, r) uniform_int_distribution<int>(l, r)(rng);
using namespace std;

main() {
    int seed;
    cin >> seed;
    mt19937 rng(seed);
    int n = Rand(1, 100);
    cout << n << endl;
    for (int i = 1; i <= n; ++i) {
        int x = Rand(1, 100);
        cout << x << endl;
    }
    int q = Rand(1, 100);
    cout << q << endl;
    while (q--) {
        int l = Rand(1, 100);
        int r = Rand(1, 100);
        cout << l << " " << r << endl;
    }
    return 0;
}

