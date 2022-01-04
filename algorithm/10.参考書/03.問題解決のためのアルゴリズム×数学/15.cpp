#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int gcd(int n, int m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int a,b;
    cin >> a >> b;

    cout << gcd(a, b) << endl;
    return 0;
}
