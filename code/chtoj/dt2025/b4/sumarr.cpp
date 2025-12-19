#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define ms(d, x) memset(d, x, sizeof(d))
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define pb push_back
#define execute cerr << "Time elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << "s" << '\n';
#define shouko 1
#define orz shouko
// dont copy my flow dude
#define task "SUMARR"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;

const int inf = 1e18;
const int mod = 1e9 + 7;
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * b) % mod; }
int sub(int a, int b) { return ((a - b) % mod + mod) % mod; }
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n;
int a[N];
int sum;
int d[N];
int pre[N];

void sub1()
{
    for (int u = 0; u < n; ++u)
    {
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // cout << i << ' ' << j << '\n';
                // cout << (i | j) << '\n';
                // cout << i << '\n';
                if ((i | j) <= u)
                {
                    // cout << i << ' ' << j << '\n';
                    sum += mul(a[i], a[j]);
                }
            }
        }   
        cout << sum % mod << ' ';
    }
    // cout << sum % mod;
}

void sub2()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            d[(i | j)] += mul(a[i], a[j]);
        }
        pre[i] = add(pre[i - 1], d[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        cout << pre[i] << ' ';
    }
}

void logic()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    if (n <= 100)
    {
        sub1();
    }
    else
    {
        sub2();
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen(task ".inp", "r"))
    {
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


3
1 2 8
0 1 2
U = i - 1

1 2 8





------------
*/