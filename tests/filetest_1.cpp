#include<bits/stdc++.h>
using namespace std;

const long long N = 1000058;
const long long os = 500000; 

long long n, k, ans;
long long a[N];
long long cnt[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (long long i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (long long i=1; i<=n; i++) {
        int sq = a[i] * a[i];
        int ned = k - sq;
        int idx = ned + os;
        if (0 <= idx && idx < N) ans += cnt[idx];
        int idx2 = a[i] + os;
        if (0 <= idx2 && idx2 < N) cnt[idx2]++;
    }
    cout << ans;
}