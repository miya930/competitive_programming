#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    if (a < b) {
        if (a < n) ans = n - a + 1;
    } else {
        ll tmp = n / a - 1;
        if (a <= n) ans++;
        if (tmp > 0) ans += tmp * b;
        if (a < n) ans += min(n%a, b-1);
    }

    cout << ans << endl;
    return 0;
}
