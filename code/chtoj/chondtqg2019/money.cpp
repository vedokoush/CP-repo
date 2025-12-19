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
#define task "Money"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int m, q;
int pre[N];
int maxx;
int val, last;

int a[N];
int b[N];


void sub1() {
    while (q--) {
        val = last = 0;
        maxx = 0;
        int x; cin >> x;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j < i; ++j) {
                if (pre[i] - pre[j - 1] <= x) {
                    if (i - j + 1 >= maxx) {
                        maxx = i - j + 1;
                        val = pre[i] - pre[j - 1];
                        last = j;
                    }
                }
            }
        }
        // cout << maxx << ' ' << last << ' ' << val << '\n';
        cout << maxx << ' ' << last << '\n';
    }

}

void v2() {
    while (q--) {
        val = last = 0;
        maxx = 0;
        int x; cin >> x;
        for (int i = 1; i <= m; ++i) {  
            // pre[i] - pre[j - 1] <= x --> 
            int j = lower_bound(pre, pre + i, pre[i] - x) - pre; 
            if (j < i and pre[i] - pre[j] <= x) {
                int len = i - j;
                if (len >= maxx) {
                    maxx = len;
                    val = pre[i] - pre[j];
                    last = j + 1; 
                }
            }
        }
        cout << maxx << ' ' << last << '\n';
    }
}

void sub2() {
    for (int i=1; i<=q; i++) {
        int s = upper_bound(pre, pre+m+1, b[i]) - pre - 1;

        if (s == 0) {
            cout << 0 << " " << 0 << '\n';
            continue;
        }

        int L = 1, R = m - s + 1;
        int ans = 1;

        while (L <= R) {
            int mid = (L+R) / 2;
            int sum = pre[mid+s-1] - pre[mid-1];

            if (sum <= b[i]) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }

        int v = a[ans];
        cout << s << " " << v << '\n';
    }
}

void logic() {
    cin >> m >> q;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    sort (a + 1, a + m + 1);
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + a[i];
    }
    if (m <= 100 and q <= 100) {
        sub1();
    }
    else if (m <= 1000 and q <= 1000) {
        v2();
    }
    else {
        for (int i = 1; i <= q; ++i) {
            cin >> b[i];
        }
        sub2();
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
