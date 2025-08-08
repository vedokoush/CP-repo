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
#define task "VIPLIST"

using namespace std;
const int N = 1e6 + 9;
const int M = 1e5 + 5;
const int inf = 1e18;
const int mod = 1e9 + 7;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, k;

vector<int> adj[N];
bool loai[N];
queue<int> q;
vector<int> ans;
int mp[N];

void logic()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        ++mp[v];
        ++mp[u];
    }

    for (int i = 1; i <= n; ++i)
    {
        if ((int)adj[i].size() < k)
        {
            loai[i] = true;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!loai[v])
            {
                mp[v]--;
                if (mp[v] < k)
                {
                    loai[v] = true;
                    q.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!loai[i])
        {
            ans.pb(i);
        }
    }

    cout << ans.size() << '\n';
    for (int u : ans)
    {
        cout << u << ' ';
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


------------
*/
