
#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define Is(mask, pos) (mask & (1LL << pos))
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s\n";

#define task "Game"

using namespace std;

const int N = 1e6 + 9;

int n;
int a[N];
map<int,int> mp;
int tmp, tmp2;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (mp[a[i]] == 0) mp[a[i]] = i;
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        if (mp[x] == 0) {
            cout << -1 << '\n';
            ++tmp;
        }
        else{
            cout << mp[x] << '\n';
            ++tmp2;
        }
    }
    if (tmp == tmp2) {
        cout << 0;
    }
    else if (tmp < tmp2) {
        cout << 1;
    }
    else cout << -1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    logic();
    return 0;
}
