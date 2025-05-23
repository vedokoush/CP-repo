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
    long long a = Rand(1, 100), b = Rand(1, 100);
    cout << a << ' ' << b << '\n';
}

int main() {
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++) {
        GenTest();
        system("./a < a.inp > a.out");
        system("./a_trau < a.inp > a.ans");

        if (system("diff a.out a.ans") != 0) {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
}