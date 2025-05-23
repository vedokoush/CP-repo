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
#define task ""


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int st[4 * N];

void update(int id, int l, int r, int pos, int val) {
    if (l > pos or r < pos) {
        return;
    }
    if (l == r) {
        st[id] += val;
        return;
    }
    int mid = l + r >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    /// [l r] [u v] [l r]
    if (u > r or v < l) {
        return -1e18;
    }
    /// [u l r v] 
    if (l >= u and r <= v) {
        return st[id];
    }
    int mid = (l + r) / 2;
    return max(get(2 * id, l, mid, u, v), 
               get(2 * id + 1, mid + 1, r, u, v));
}

void logic() {
    cin >> n >> m;
    for ()
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
