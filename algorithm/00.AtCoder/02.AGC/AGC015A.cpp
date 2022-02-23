#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n ,a, b;
    cin >> n >> a >> b;

    if (a > b || (a != b && n == 1)) {
        cout << 0 << endl;
        return 0;
    } else if (a == b || n == 2) {
        cout << 1 << endl;
        return 0;
    }

    cout << b*(n-2) - a*(n-2) + 1 << endl;

    return 0;
}
