#include <bits/stdc++.h>
using namespace std;
#define task "COMPLE"
#define int long long
#define ll long long
#define fi first
#define se second
#define ii pair<int, int>
#define iii pair<ll, ii>
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> ok(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && j != k && k != i)
                {
                    if (a[i][j] == '1' && a[j][k] == '1' && a[k][i] == '1')
                    {
                        ok[i] = ok[j] = ok[k] = 1;
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += ok[i];
    cout << ans ;
    cerr << endl
         << "TIME : " << clock() * 0.001 << "s" << endl;
}