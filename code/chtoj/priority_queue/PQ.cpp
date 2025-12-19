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
#define task "PQ"

using namespace std;
const int N = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;

int n;
multiset<int> s;

void logic() {
    cin >> n;
    while (n--) {
        char c; 
        cin >> c;
        if (c == '+') {
            int x; cin >> x;
            s.insert(x);
        } 
        else if (c == '-') {
            if (!s.empty()) {
                int mx = *s.rbegin();
                while (!s.empty() and *s.rbegin() == mx)
                    s.erase(prev(s.end()));
            }
        }
    }

    vector<int> res;
    for (auto it = s.rbegin(); it != s.rend(); ++it) res.pb(*it);
    res.erase(unique(all(res)), res.end());

    cout << res.size() << '\n';
    for (auto x : res) cout << x << ' ';
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }

    logic();

    return 0;
}

/*
--/shouko\--

*/