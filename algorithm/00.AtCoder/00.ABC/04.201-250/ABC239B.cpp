#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x;
    cin >> x;

    if (x >= 0) cout << x / 10 << endl;
    else {
        x *= -1;
        x = (x+9)/10;
        cout << -1*x << endl;
    }

    return 0;
}
