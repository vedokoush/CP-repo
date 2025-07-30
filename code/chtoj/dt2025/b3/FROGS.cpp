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
#define task "FROGS"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int h[N];
int j[N];
stack<int> st;
int b[N];

void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> j[i];
    }
    for (int i = 1; i <= n; ++i) {
        while (!st.empty() && h[st.top()] < h[i]) {
            b[st.top()] = i;
            st.pop();
        }
        st.push(i);                          
    }
    // for (int i = 1; i <= n; ++i) {
    //     cout << b[i + j[i]] << ' ';
    // }
    // for (int i = 1; i <= n; ++i) {
    //     cout <
    // }
    // cout << b[b[1]] << ' ' << b[b[b[2]]] << ' ' << b[b[3]] << ' ' << b[b[b[b[4]]]];
    // cout << '\n';
    for (int i = 1; i <= n; ++i) {
        int x = j[i];
        int ans = i;
        while (x > 0) {
            ans = b[ans];
            x--;
        }
        if (h[ans] == 0) {
            cout << -1 << ' ';
        }
        else {
            cout << h[ans] << ' ';
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
