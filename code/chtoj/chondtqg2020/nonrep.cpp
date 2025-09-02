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
#define task "NONREP"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
bool c[15];

bool check(int x) {
    if (x == 0) return false;
    int cnt[10] = {0};
    while (x != 0) {
        int d = x % 10;
        x /= 10;
        ++cnt[d];
    }
    if (cnt[0] != 0) return false;
    for (int i = 0; i <= 9; ++i) {
        if (cnt[i] > 1) return false;
    }
    return true;
}

void sub1() {
    int m = n;
    while (!check(m)) ++m;
    cout << m << '\n';
}

void sub2() {
    string s = to_string(n);
    ms(c, false);
    for (int i = 0; i < s.size(); ++i) {
        int d = s[i] - '0';
        if (d == 0 or c[d]) {
            for (int x = d + 1; x <= 9; ++x) {
                if (!c[x]) {
                    s[i] = char(x + '0');
                    c[x] = true;
                    int cur = 1;
                    for (int j = i + 1; j < (int)s.size(); ++j) {
                        while (cur <= 9 and c[cur]) ++cur;
                        if (cur > 9) return;
                        s[j] = char(cur + '0');
                        c[cur] = true;
                    }
                    cout << stoll(s) << '\n';
                    return;
                }
            }
            return;
        } else {
            c[d] = true;
        }
    }
    cout << s << '\n';
}

void logic() {
    while (cin >> n) {
        if (n <= 1e3) sub1();
        else sub2();
    }
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