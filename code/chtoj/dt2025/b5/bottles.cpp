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
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, k;
int a[N], pre[N], f[N], dp[N];
deque<int> dq;
int trace[N];

void push(int i) {
    while (!dq.empty() && f[i] >= f[dq.back()])
        dq.pop_back();
    dq.push_back(i);
}

void pop(int i) {
    if (!dq.empty() && dq.front() == i)
        dq.pop_front();
}

void logic() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    f[0] = pre[0];
    f[1] = dp[0] - pre[1];
    push(0);

    for (int i = 1; i <= n; ++i) {
        push(i);
        dp[i] = f[dq.front()] + pre[i];
        f[i + 1] = dp[i] - pre[i + 1];
        if (i - k + 1 >= 0) {
            pop(i - k + 1);
        }
    }
    cout << dp[n];
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

/*
--/shouko\--
DRAFT:

------------
*/
