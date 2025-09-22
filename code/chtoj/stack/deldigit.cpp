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
#define task "DELDIGIT"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

stack<int> st;
int cnt;
vector<char> ans;

void logic() {
    string s; cin >> s;
    int n; cin >> n;
    for (int i = 0; i < (int)s.size(); ++i) {
        while (!st.empty() and s[i] > s[st.top()] and n > 0) {
            st.pop();
            n--;
        }
        st.push(i);
    }

    while (!st.empty ()) {
        ans.push_back (st.top ());
        st.pop ();
    }
    reverse (ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << s[ans[i]];
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
