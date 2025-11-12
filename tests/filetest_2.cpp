#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long t = 0;
    for (int i = 0; i < n; i++)
    {
        t += a[i];
    }
    if (t % 3 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    long long s = 0, c1 = 0, c2 = 0;
    long long p = t / 3;
    vector<long long> tong(n, 0);
    s = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        s += a[i];
        if (s == p)
        {
            tong[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        tong[i] += tong[i + 1];
    }
    s = 0;
    for (int i = 0; i < n - 2; i++)
    {
        s += a[i];
        if (s == p)
        {
            c2 += tong[i + 2];
        }
    }
    cout << c2 << endl;
    return 0;
}