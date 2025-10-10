#include<bits/stdc++.h>
#define int long long
using namespace std;

const int pad = 1000058;

int n, ans = 0;
int a[pad];
unordered_map<int, int> mp;

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen("BEAUTARR.inp", "r")) {
        freopen("BEAUTARR.inp", "r", stdin);
        freopen("BEAUTARR.out", "w", stdout);
    }
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int L = 1;
    for (int R = 1; R <= n; R++) {
        mp[a[R]]++;
        while (mp[a[R]] > 2) {
            mp[a[L]]--;
            L++;
        }
        ans += (R - L + 1);
    }

    cout << ans << "\n";
}