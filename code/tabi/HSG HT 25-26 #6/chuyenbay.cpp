#include <bits/stdc++.h>
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
#define task ""

#define On(mask, pos) ((mask) | (1LL << (pos)))
#define Off(mask, pos) ((mask) ^ (1LL << (pos)))
#define Is(mask, pos) ((mask) & (1LL << (pos)))

using namespace std;
const int N = 21;
const int M = 1058576;
const int inf = 1e18;
const int mod = 1e9 + 7;

int add(int a, int b) { return ( (a + b) % mod + mod ) % mod; }
int mul(int a, int b) { return (int)((1LL * a * b) % mod); }
int sub(int a, int b) { return ((a - b) % mod + mod) % mod; }

int n, m;
bool adj[N][N];
int dp[M][N];

void logic()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    ms(adj, 0);
    ms(dp, 0);

    for (int i = 1; i <= m; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u][v] = true;
    }

    dp[1][1] = 1;

    for (int mask = 1; mask < (1 << n); ++mask)
    {
        if (!Is(mask, 0)) continue;
        for (int u = 1; u <= n; ++u)
        {
            if (!Is(mask, u - 1)) continue; 
            int cur = dp[mask][u];
            if (cur == 0) continue;
            for (int v = 1; v <= n; ++v)
            {
                if (adj[u][v] && !Is(mask, v - 1))
                {
                    int nmask = On(mask, v - 1);
                    dp[nmask][v] = add(dp[nmask][v], cur);
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n];
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    logic();
    return 0;
}