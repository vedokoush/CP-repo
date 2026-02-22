#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 9;
const int inf = 1e18;

int cnt;
int x;
int val[3 * N][3 * N];
pair<int, int> idx[N];

void init(void) {
    cin >> x;
}


/*

1
2  3
4  5  6 
7  8  9  10
11 12 13 14 15
16 17 18 19 20 21

*/

namespace subtask {
    bool check() {return true;}
    pair<int, int> tam_giac_la_tac_giam(int x) {
        int r = (int)ceil((sqrt(8.0 * x + 1) - 1) / 2);
        int prev = r * (r - 1) / 2;
        int c = x - prev;
        return {r, c};
    }
    int tam_giac_la_tac_giam_rev(int r, int c) {
        if (c < 1 || c > r || r < 1) return -1;
        return r * (r - 1) / 2 + c;
    }
    void solve(void) {
        auto p = tam_giac_la_tac_giam(x);
        // cout << p.first << ' ' << p.second << '\n';
        int c = p.second;
        int r = p.first;
        
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t; cin >> t;
    while(t--) {
        init();
        if (subtask::check()) subtask::solve();
    }

}

