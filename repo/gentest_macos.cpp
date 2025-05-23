#include <bits/stdc++.h>
#define NAME "a"
using namespace std;

const int NTEST = 100;

mt19937_64 rd(time(0));

long long Rand(long long l, long long h) {
    return uniform_int_distribution<long long>(l, h)(rd);
}

void GenTest() {
    ofstream cout (NAME ".inp");
    long long L = Rand(1, 100), n = Rand(1, 10);
    cout << L << ' ' << n << '\n';
    for (int i = 1; i <= n; i++) {
        cout << Rand(0, 50) << ' ' << Rand(1, L) << '\n';
    }
}

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        GenTest();

        // Run the main solution and the brute-force checker
        system("./a < a.inp > a.out");
        system("./a_trau < a.inp > a.ans");

        // Use diff instead of fc
        if (system("diff a.out a.ans") != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
}