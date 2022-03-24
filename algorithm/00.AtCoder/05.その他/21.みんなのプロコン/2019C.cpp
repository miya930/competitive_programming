#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll k, a, b;
    cin >> k >> a >> b;

    ll ans = 0;
    ll num = a+2;
    if (num-1 > k || a+2 >= b) ans = 1 + k;
    else {
        ans = b;
        k -= (num-1);

        ll diff = b-a;
        ans += (k/2)*diff;
        ans += k%2;
    }

    cout << ans << endl;
    return 0;
}
