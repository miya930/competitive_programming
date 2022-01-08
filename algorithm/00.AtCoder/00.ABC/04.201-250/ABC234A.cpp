#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int t) {
    int res = t*t + t*2 + 3;
    return res;
}

int main()
{
    int t;
    cin >> t;

    int ff = f(t) + t;
    int fff = f(ff);
    int ffff = f(t);
    int a = f(ffff);
    int two = f(fff+a);
    cout << two << endl;

    return 0;
}

