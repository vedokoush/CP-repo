#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

void solve() {
    long long m, n;
    cin >> m >> n;
    bool found = false;

    // 1. Chữ số lẻ (1, 3, 5, 7, 9)
    for (long long i = 1; i <= 9; i += 2) {
        if (i >= m && i <= n && isPrime(i)) {
            cout << i << "\n";
            found = true;
        }
    }

    // 2. Các số đối xứng có 2 chữ số (11, 33, 55, 77, 99)
    for (long long i = 1; i <= 9; i += 2) {
        long long num = i * 10 + i;
        if (num >= m && num <= n && isPrime(num)) {
            cout << num << "\n";
            found = true;
        }
    }

    // 3. Tạo số đối xứng có >= 3 chữ số
    // Sinh nửa đầu (left), tạo số nguyên tố đối xứng, kiểm tra range
    for (long long len = 3; len <= 9; len++) {
        long long start = 1;
        for (int k = 1; k < len / 2; k++) start *= 10;
        long long end = start * 10 - 1;

        for (long long left = start; left <= end; left++) {
            string s = to_string(left);
            string rev = s;
            reverse(rev.begin(), rev.end());

            long long num;
            if (len % 2 == 0) {
                num = stoll(s + rev);
            } else {
                num = stoll(s + rev.substr(1));
            }

            if (num > n) continue; // Optimization: if num > n, larger lefts will also be > n
            if (num >= m && isPrime(num)) {
                cout << num << "\n";
                found = true;
            }
        }
    }

    if (!found) cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
