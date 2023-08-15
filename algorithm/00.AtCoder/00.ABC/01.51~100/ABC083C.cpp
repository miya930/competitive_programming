#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, y;
    cin >> x >> y;

    ll mo = y % x;
    y -= mo;

    ll ans = 0;
    while(x <= y) {
        ans++;
        x *= 2;
    }
    cout << ans << endl;
    return 0;
}
