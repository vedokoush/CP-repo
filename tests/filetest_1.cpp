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
#define task "LBRACKET"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

string s;
stack<int> st;
int ans, l, r;

void logic() {
    cin >> s;
    while (!st.empty()) st.pop();  // reset stack
    st.push(-1);

    ans = 0, l = r = -1; // reset kết quả

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else { // ')'
            if (!st.empty()) st.pop();
            if (!st.empty()) {
                int t = i - st.top();
                if (t >= ans) {
                    ans = t;
                    l = st.top() + 1;
                    r = i;
                }
            } else {
                st.push(i);
            }
        }
    }
    
    cout << ans << '\n';
    cout << l << ' ' << r << '\n'; // đang là 0-index, muốn 1-index thì l+1, r+1
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
*/