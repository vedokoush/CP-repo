#include<bits/stdc++.h>
#define int long long
#define text ""
#define fi first
#define sec second
#define pii pair<int, int>
#define ms(d, x) memset(d, x, sizeof(d))
#define pb push_back
using namespace std;

const int pad = 1000058;

string s;
int cntl = 0, ans = 1e18, L = 0;
int cnt[pad];

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen(text".inp", "r")) {
        freopen(text".inp", "r", stdin);
        freopen(text".out", "w", stdout);
    }

    cin >> s;
    for (int i=0; i<s.size(); i++) {
        int lt = s[i] - 'A';
        cnt[lt]++;
        if (cnt[lt] == 1) cntl++;

        while (cntl == 26) {
            ans = min(ans, i - L + 1);

            int lt2 = s[L] - 'A';
            cnt[lt2]--;
            if (cnt[lt2] == 0) cntl--;
            L++;
        }
    }

    if (ans == 1e18) cout << -1;
    else cout << ans;
}