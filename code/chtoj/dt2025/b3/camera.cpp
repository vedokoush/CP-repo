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

int n, a[N], res[N];
string s;


void logic() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    cin >> s;

    // Left to Right for E
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == 'E') {
            while (!st.empty() && a[st.top()] < a[i]) {
                res[st.top()]++;
                st.pop();
            }
            st.push(i);
        } else {
            while (!st.empty()) st.pop();
        }
    }

    // Right to Left for W
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; --i) {
        if (s[i - 1] == 'W') {
            while (!st.empty() && a[st.top()] < a[i]) {
                res[st.top()]++;
                st.pop();
            }
            st.push(i);
        } else {
            while (!st.empty()) st.pop();
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
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
