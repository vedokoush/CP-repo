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
#define task "PARTITION"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int s, n;
int a[N];
int sum;
priority_queue<int, vector<int>, greater<int>> pq;


void logic() {
    cin >> s >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
        pq.push(a[i]);
    }

    if (sum < s) {
        pq.push(s - sum);
    }

    int ans = 0;
    while (pq.size() > 1) {
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        ans += x + y;
        pq.push(x + y);
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
