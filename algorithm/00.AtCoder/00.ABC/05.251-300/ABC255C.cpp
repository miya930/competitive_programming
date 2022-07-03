#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll x, a, d, n;
    cin >> x >> a >> d >> n;

    ll ans;
    ll up, low;

    if (d < 0) {
        up = a;
        low = a + (n-1)*d;
    } else {
        low = a;
        up = a + (n-1)*d;
    }

    if (x <= low) {
        ans = low - x;
    } else if (x >= up) {
        ans = x - up;
    } else {
        ll diff = x - a;
        if (d < 0) {
            d = -d;
            diff = -diff;
        }
        ll t1 = diff%d;
        ll t2 = (d-t1);
        ans = min(t1, t2);
    }

    cout << ans << endl;
    return 0;
}
