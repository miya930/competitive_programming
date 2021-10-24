#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ll x;
    cin >> x;

    ll ans = x/11*2;

    if (x%11 > 6) ans += 2;
    else if (x%11 > 0) ans++;

    cout << ans << endl;

    return 0;
}
