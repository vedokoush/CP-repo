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
#define task ""

using namespace std;

const int N = 1e6 + 9;
int n;
int a[N];
map<int, int> mp;
vector<int> t;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (!mp[a[i]]) t.pb(a[i]);
        ++mp[a[i]];
    }

    cout << t.size() << '\n';
    for (int x : t) {
        cout << x << ' ' << mp[x] << '\n';
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

    logic();
    return 0;
}

/*
--/shouko\--
*/