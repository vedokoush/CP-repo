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
int n, k;
int a[N];
deque<int> dq;

void push(int i) {
    while (!dq.empty() && a[i] <= a[dq.back()]) {
        dq.pop_back();
    }
    dq.pb(i);
}

void pop(int i) {
    if (i == dq.front()) {
        dq.pop_front();
    }
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        push(i);
        if (i >= k) {
            cout << a[dq.front()] << ' ';
            pop(i - k + 1);
        }
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

/*
SEGMENT TREE

#include <bits/stdc++.h>
#define int long long
#define range(i, l, r) for(int i = l; i <= r; ++i)
#define task ""
using namespace std;

const int N = 3.5e6 + 9;
const int INF = 1e18;

int n, k;
int a[N];
int tree[4 * N];

void build(int id, int l, int r) {
    if (l == r) {
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}

int getMin(int id, int l, int r, int u, int v) {
    if (v < l || u > r) return INF;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return min(getMin(id * 2, l, mid, u, v),
               getMin(id * 2 + 1, mid + 1, r, u, v));
}

void solve() {
    cin >> n >> k;
    range(i, 1, n) cin >> a[i];
    build(1, 1, n);
    range(i, 1, n - k + 1) {
        cout << getMin(1, 1, n, i, i + k - 1) << ' ';
    }
    cout << '\n';
}

int32_t main() {
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if (fopen(task ".inp", "r")) {
            freopen(task ".inp", "r", stdin);
            freopen(task ".out", "w", stdout);
        }
    }
    solve();
}

*/
