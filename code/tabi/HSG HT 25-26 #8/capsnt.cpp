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
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

bool f[N];
int n;

void sieve() {
    ms(f, true);
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; ++i) {
        if (f[i]) {
            for (int j = i * i; j <= N; j += i) {
                f[j] = false;
            }
        }
    }
}

void logic() {
    sieve();
    cin >> n;
    int k = 1;
    while (f[n + k] == false) {
        ++k;
    }
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ';
    }
    cout << '\n';
    for (int i = k - 1; i >= 1; i--) {
        cout << i << ' '; 
    }
    for (int i = n; i >= k; i--) {
        cout << i << ' ';
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
