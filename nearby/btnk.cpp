#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define str string
#define mp unordered_map<int, int>
#define ii pair<int, int>
#define iii pair<int, ii>
#define vi vector<int>
#define vii vector<ii>
#define fi first
#define se second
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define F                            \
    ios_base::sync_with_stdio(NULL); \
    cin.tie(NULL);
#define file(task)                         \
    if (fopen(task ".inp", "r"))           \
    {                                      \
        freopen(task ".inp", "r", stdin);  \
        freopen(task ".out", "w", stdout); \
    }
using namespace std;

const int N = 1e6 + 12;
const int T = 1e3 + 12;
const ll inf = (ll)4e18;
const int mod = 111539786 ;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

ll n, k;
str s;
ll dp[T][T][3], next1[N], next2[N];

ll dqcn(int i, int cnt, int check)
{
    if (dp[i][cnt][check] != -1)
    {
        return dp[i][cnt][check];
    }
    int res1 = (cnt == 0 && check);
    if (cnt < k && next1[i] < n + 1)
    {
        res1 = (res1 + dqcn(next1[i], cnt + 1, (check || 1 + cnt == k))) % mod;
    }
    if (cnt > 0 && next2[i] < n + 1)
    {
        res1 = (res1 + dqcn(next2[i], cnt - 1, check)) % mod;
    }
    return dp[i][cnt][check] = res1;
}
void solve()
{
    cin >> s >> k;
    n = s.size();
    s = " " + s;
    int x = n + 1, y = n + 1;
    for (int i = n; i >= 1; i--)
    {
        next1[i] = x;
        next2[i] = y;
        if (s[i] == '(')
        {
            x = i;
        }
        else
        {
            y = i;
        }
    }
    next1[0] = x;
    next2[0] = y;
    memset(dp, -1, sizeof(dp));
    cout << dqcn(0, 0, 0);
}

int main()
{
    F;
    file("BTNK");
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << "Time: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
