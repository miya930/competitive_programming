#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int func(int n) {
    if (n == 0) return 1;
    else return n * func(n-1);
}

int main()
{
    int n;
    cin >> n;

    cout << func(n) << endl;

    return 0;
}
