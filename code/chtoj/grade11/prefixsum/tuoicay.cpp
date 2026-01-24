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
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';

/*
  .-')    ('-. .-.                          .-. .-')               
 ( OO ). ( OO )  /                          \  ( OO )              
(_)---\_),--. ,--. .-'),-----.  ,--. ,--.   ,--. ,--.  .-'),-----. 
/    _ | |  | |  |( OO'  .-.  ' |  | |  |   |  .'   / ( OO'  .-.  '
\  :` `. |   .|  |/   |  | |  | |  | | .-') |      /, /   |  | |  |
 '..`''.)|       |\_) |  |\|  | |  |_|( OO )|     ' _)\_) |  |\|  |
.-._)   \|  .-.  |  \ |  | |  | |  | | `-' /|  .   \    \ |  | |  |
\       /|  | |  |   `'  '-'  '('  '-'(_.-' |  |\   \    `'  '-'  '
 `-----' `--' `--'     `-----'   `-----'    `--' '--'      `-----'                                                                        
*/

#define task ""


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int base = 311;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int n, m;
int a[N], lazy[4 * N], tree[4 * N];

void down(int id) {
    if (lazy[id]) {  
        int x = lazy[id];

        lazy[id * 2] += x;
        tree[id * 2] += x;

        lazy[id * 2 + 1] += x;
        tree[id * 2 + 1] += x;

        lazy[id] = 0; 
    }
}

// a[u -> v] += val
void update(int id, int l, int r, int u, int v, int val) {
    if (l > v || r < u) {
        return;
    }
    if (l >= u && r <= v) {
        tree[id] += val;
        lazy[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    down(id);
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
}

int get(int id, int l, int r, int u, int v) {
    if (u > r || v < l) {
        return -1e18;
    }
    if (l >= u && r <= v) {
        return tree[id];
    }
    int mid = (l + r) / 2;
    down(id);
    return max(get(2 * id, l, mid, u, v), 
               get(2 * id + 1, mid + 1, r, u, v));
}

void logic() {
    cin >> n >> m;
    while (m--) {
        int l, r, k; cin >> l >> r >> k;
        update(1, 1, n, l, r, k);
    }
    for (int i = 1; i <= n; ++i) {
        cout << get(1, 1, n, i, i) << ' ';
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
    
    // freopen(task ".inp", "r", stdin);
    // freopen(task ".out", "w", stdout);

    logic();

    return 0;
}
