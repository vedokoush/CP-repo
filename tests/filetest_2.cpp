#include <bits/stdc++.h>
#define skibidi                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define file(tenfile)                         \
    if (fopen(tenfile ".inp", "r"))           \
    {                                         \
        freopen(tenfile ".inp", "r", stdin);  \
        freopen(tenfile ".out", "w", stdout); \
    }
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<int, ii>
#define iii pair<int, ii>
#define On(mask, pos) (mask | (1LL << pos))
#define Off(mask, pos) (mask ^ (1LL << pos))
#define endl "\n"
using namespace std;
const int N = 1e6 + 69;
ll n, a[N], dist[N], m, S, T;
vector<ll> adj[N], ans1;
queue<ll> q;
ll ans;
void bfs(int S)
{
    for (int i = 1; i <= n; i++)
        dist[i] = 1e18;
    dist[S] = 0;
    q.push(S);
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (dist[v] > dist[u] + 1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        ll k;
        cin >> k;
        for (int j = 1; j <= k; j++)
        {
            ll x;
            cin >> x;
            adj[i].push_back(x);
        }
    }
    bfs(S);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != 1e18)
           {
                ans++;
                ans1.push_back(i);
           }
    }
    cout << ans << endl;
    for (auto x : ans1)
    {
        cout << x << " ";
    }
}
int32_t main()
{
    skibidi;
    cin >> n >> S;
    solve();
}