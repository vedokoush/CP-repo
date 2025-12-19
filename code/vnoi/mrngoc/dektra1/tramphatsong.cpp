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
const int N = 1e6;
const int M = 1e6 + 9;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[M];
int k;

bool check(int x) {
    for (int i = 0; i < n; ++i) {
        deque<int> dq;
        for (int j = 0; j < n; ++j) {
            int val = a[(i + j) % n];
            if (i + j >= n) {
                val += N;
            }
            dq.pb(val);
        }

        int cnt = 0;

        while (!dq.empty()) {
            int r = dq.front() + 2 * x;
            ++cnt;
            
            while (!dq.empty() and dq.front() <= r) {
                dq.pop_front();
            }
            if (cnt > k) break;
        }
        if (cnt <= k) return true;
    }
    return false;
}

void logic() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> k;
    int l = 0, r = N / 2, ans = r;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
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
