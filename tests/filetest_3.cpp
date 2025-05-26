#include <bits/stdc++.h>
using namespace std;

#define NAME "EBOLA"
#define int long long
const int N = 2 * 1e5 + 5;
const int INF = 1e9;

int n, m, dist[N], s, t;
vector < int > p[N];

void BFS (int start)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[start] = 0;
    queue < int > q;
    q.push (start);

    while (!q.empty ())
    {
        int node = q.front ();
        q.pop ();

        for (auto v : p[node])
        {
            if (dist[v] > dist[node] + 1)
            {
                dist[v] = dist[node] + 1;
                q.push (v);
            }
        }
    }
}

void solve()
{  
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int x; cin >> x;
            p[i].push_back (x); 
        }
    }

    BFS (s);
    vector < int > ans;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] != INF) ans.push_back (i);
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if(fopen(NAME ".inp", "r")){
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }

    solve ();
}
