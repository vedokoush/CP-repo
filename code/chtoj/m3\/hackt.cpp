#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, pair<int, int>>
#define task "HACKT"
using namespace std;

const int N = 1e6 + 9;
const int inf = 1e18;

int n, k;
int a[N];
int neg;
int pos;
int suml, sumr;
int pre[N];
int ans;
int t;

void sub1() {
    pos = 0;
    suml = sumr = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < 0) {
            pos = i;
            break;
        }
    }

    for (int i = 1; i < pos; ++i) suml += a[i];
    for (int i = pos + 1; i <= n; ++i) sumr += a[i];

    if (k == n) {
        cout << suml + sumr + a[pos];
        return;
    }
    cout << max(suml + sumr + a[pos], max(suml, sumr));
}

void sub2() {
    ans = -inf;
    t = 0;
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }

    t = pre[0];
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, pre[i] - t);
        t = min(t, pre[i]);
    }
    cout << ans;
}

void logic() {
    cin >> n >> k;
    neg = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < 0) ++neg;
    }

    if (neg == 1) {
        sub1();
    } else {
        sub2();
    }
}

int32_t main(){
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