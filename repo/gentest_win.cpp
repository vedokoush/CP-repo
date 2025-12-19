#include <bits/stdc++.h>
#define NAME "a"
using namespace std;

const int NTEST = 100;

mt19937_64 rd(time(0));

long long Rand(long long l, long long h) {
    return uniform_int_distribution<long long>(l, h)(rd);
}

void GenTest() {
    ofstream cout (NAME".inp");
    long long L = Rand(1, 100), n = Rand(1, 10);

    cout << L << ' ' << n << '\n';

    for (int i=1; i<=n; i++) {
        cout << Rand(0, 50) << ' ' << Rand(1, L) << '\n';
    }
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        GenTest();

        // NEED FREOPEN

        //system(NAME"_trau.exe");
        //system(NAME".exe");

        // NO FREOPEN (Just Del the slash)

        system(NAME".exe <"NAME".inp >"NAME".out");
        system(NAME"_trau.exe <"NAME".inp >"NAME".ans");

        if (system("fc "NAME".out "NAME".ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
}