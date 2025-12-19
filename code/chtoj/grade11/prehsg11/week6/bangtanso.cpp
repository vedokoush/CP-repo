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
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[N];
int b[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int k = 0;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || a[i] != a[i - 1]) {
            b[++k] = a[i];
        }
    }

    cout << k << '\n';
    for (int i = 1; i <= k; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (a[j] == b[i]) ++cnt;
        }
        cout << b[i] << ' ' << cnt << '\n';
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
DRAFT:
------------
*/