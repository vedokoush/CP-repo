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
#define task "NUM39"

using namespace std;
const int N = 333333;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
vector<int> a;
int mid;
vector<int> g;   
bool check = false;

vector<ii> b;   

void ql(int i, vector<int>& s, vector<int>& cnt) {
    if (check) return;

    if (i == 3 * n) {
        if (s[0] == mid && s[1] == mid && s[2] == mid) {
            for (int j = 0; j < 3 * n; ++j) cout << g[j];
            cout << '\n';
            check = true;
        }
        return;
    }

    for (int j = 0; j < 3; ++j) {
        if (cnt[j] < n && s[j] + b[i].fi <= mid) {
            s[j] += b[i].fi;
            cnt[j]++;
            g[b[i].se] = j + 1;

            ql(i + 1, s, cnt);

            s[j] -= b[i].fi;
            cnt[j]--;
            if (check) return;
        }
    }
}

bool cm

void logic() {
    cin >> n;
    a.assign(3 * n, 0);

    int sum = 0;
    for (int i = 0; i < 3 * n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 3 != 0) {
        cout << "-1\n";
        return;
    }

    mid = sum / 3;
    g.assign(3 * n, 0);
    check = false;

    b.clear();
    b.reserve(3 * n);
    for (int i = 0; i < 3 * n; ++i) b.pb({a[i], i});
    sort(b.begin(), b.end(), [](const ii& A, const ii& B){ return A.fi > B.fi; });

    if (b[0].fi > mid) {
        cout << "-1\n";
        return;
    }

    vector<int> s(3, 0), cnt(3, 0);
    ql(0, s, cnt);

    if (!check) cout << "-1\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }

    int t; 
    if (!(cin >> t)) return 0;
    while (t--) {
        logic();
    }
    return 0;
}