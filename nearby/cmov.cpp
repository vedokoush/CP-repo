#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d,x) memset(d, x, sizeof(d))
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define Is(mask, pos) (mask & (1LL << pos))
#define On(mask, pos) (mask  (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';

/*
  .-')    ('-. .-.                          .-. .-')
 ( OO ). ( OO )  /                          \  ( OO )
(_)---\_),--. ,--. .-'),-----.  ,--. ,--.   ,--. ,--.  .-'),-----.
/    _ | |  | |  |( OO'  .-.  ' |  | |  |   |  .'   / ( OO'  .-.  '
\  :` `. |   .|  |/   |  | |  | |  | | .-') |      /, /   |  | |  |
 '..`''.)|       |\_) |  |\|  | |  |_|( OO )|     ' _)\_) |  |\|  |
.-._)   \|  .-.  |  \ |  | |  | |  | | `-' /|  .   \    \ |  | |  |
\       /|  | |  |   `'  '-'  '('  '-'(_.-' |  |\   \    `'  '-'  '
 `-----' `--' `--'     `-----'   `-----'    `--' '--'      `-----'
*/

#define task "CMOV"


using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
const int base = 311;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int add(int a, int b) {return (a + b) % mod;}
int mul(int a, int b) {return (a * b) % mod;}
int sub(int a, int b) {return ((a - b) % mod + mod) % mod;}

int n, k;
int dp[N];

struct Matrix {
    int a[3][3];
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C{};
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int t = 0; t < 3; ++t)
                C.a[i][j] = (C.a[i][j] + A.a[i][t] * B.a[t][j]) % k;
    return C;
}

Matrix power(Matrix A, int exp) {
    Matrix res{};
    for (int i = 0; i < 3; ++i) res.a[i][i] = 1;
    while (exp) {
        if (exp & 1) res = multiply(res, A);
        A = multiply(A, A);
        exp >>= 1;
    }
    return res;
}

void sub2() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        dp[i] %= k;
    }
    cout << dp[n];
}

void sub3() {
    Matrix M{};
    M.a[0][0] = 1; M.a[0][1] = 1; M.a[0][2] = 1;
    M.a[1][0] = 1; M.a[1][1] = 0; M.a[1][2] = 0;
    M.a[2][0] = 0; M.a[2][1] = 1; M.a[2][2] = 0;

    Matrix P = power(M, n - 3);

    int f3 = 4 % k, f2 = 2 % k, f1 = 1 % k;
    int ans = (P.a[0][0] * f3 + P.a[0][1] * f2 + P.a[0][2] * f1) % k;
    cout << ans;
}


void logic() {
    cin >> n >> k;
    if (n <= 1000000) sub2();
    else sub3();

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
