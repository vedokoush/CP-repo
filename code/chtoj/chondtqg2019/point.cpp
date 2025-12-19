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
#define task "POINT"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[N], pos[N];
vector<int> seq, lis;

void logic() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int val = 1; val <= n; val++) {
        vector<int> tmp;
        for (int d = -1; d <= 1; d++) {
            int chk = val + d;
            if (chk >= 1 && chk <= n) tmp.pb(pos[chk]);
        }
        sort(tmp.rbegin(), tmp.rend());
        for (int x : tmp) seq.pb(x);
    }

    for (int v : seq) {
        int l = 0, r = (int)lis.size() - 1, res = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (lis[mid] >= v) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        if (res == -1) lis.pb(v);
        else lis[res] = v;
    }

    cout << lis.size() << "\n";
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