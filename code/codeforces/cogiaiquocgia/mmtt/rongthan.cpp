#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "pref" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task ""


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n, k;
int a[N];
int dp[N][3], st[4 * N], pref[N];

void update(int id, int l, int r, int pos, int val)
{
    if (l > pos || r < pos) {
        return;
    }
    if (l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v)
{
    if (l > v or r < u) {
        return -inf;
    }
    if (l >= u and r <= v) {
        return st[id];
    }
    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v), 
               get(id * 2 + 1, mid + 1, r, u, v));
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    update(1, 0, n, 0, 0);
    for (int i = 1; i <= n; i++){
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        int x = get(1, 0, n, max(i - k + 2, 1LL) - 1, i - 1);
        dp[i][1] = x + pref[i];
        update(1, 0, n, i, dp[i][0] - pref[i]);
    }

    cout << max(dp[n][1], dp[n][0]);

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
