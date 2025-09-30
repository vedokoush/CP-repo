#include<bits/stdc++.h>
#define int long long
using namespace std;

const int pad = 3000058;

int m, n, ans = 0;
int a[pad], b[pad];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen("BALL.inp", "r")) {
        freopen("BALL.inp", "r", stdin);
        freopen("BALL.out", "w", stdout);
    }
    cin >> m >> n;
    for (int i=1; i<=m; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];

    sort(a+1, a+m+1); sort(b+1, b+n+1);

    int L = 1, R = n/2 + 1;
    int i = 0;
    while (i<=m && L<=n/2 && R<=n) {
        if(b[L] >= a[i]) {
            i++;
            continue;
        }
        while(R<=n && b[R] <= a[i]) R++;
        if (R <= n) ans++;
        L++;
        R++;
        i++;
    }
    cout << ans;
}