#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, r;
    cin >> n >> r;

    ll a = 1, b = 1, c = 1;
    for (int i = 2; i <= n; ++i) a *= i;
    for (int i = 2; i <= r; ++i) b *= i;
    for (int i = 2; i <= n-r; ++i) c *= i;

    cout << a / b / c << endl;

    return 0;
}
