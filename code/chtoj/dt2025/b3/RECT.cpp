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
#define task "RECT"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[N];
stack<int> st, nst;
int l[N], r[N];
int m;
int b[N];

tuple<int, ii, int> solve(int a[]) {
    while (!st.empty()) st.pop();
    for (int i = 1; i <= n; ++i) {
        l[i] = r[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() and a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            l[i] = 1;
        }
        else {
            l[i] = st.top() + 1;
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; --i) {
        while (!st.empty() and a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty()) {
            r[i] = n;
        }  
        else {
            r[i] = st.top() - 1;
        }  
        st.push(i);
    }
    int ans = 0;
    ii upl = {0, 0};
    int hei = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans < a[i] * (r[i] - l[i] + 1)) {
            ans = a[i] * (r[i] - l[i] + 1);
            upl = {l[i], r[i]};
            hei = a[i];
        }
    }
    return {ans, upl, hei};
}

void logic() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        b[i] = m - a[i];
    }
    auto [ans1, upl1, h1] = solve(a);
    auto [ans2, upl2, h2] = solve(b);

    if (ans1 > ans2) {
        cout << ans1 << '\n';
        cout << 1 << ' ' << upl1.fi << '\n';
        cout << h1 << ' ' << upl1.se << '\n';
    } else {
        cout << ans2 << '\n';
        cout << m - h2 + 1 << ' ' << upl2.fi << '\n';
        cout << m << ' ' << upl2.se << '\n';
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

/*
--/shouko\--
DRAFT:


------------
*/
