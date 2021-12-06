#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    ll ini = 1, upper = 1;
    for (ll i = 1; i <= 15; ++i) {
        ll now = ini;
        ll nowu = upper;
        if (n < now) break;
        while (1) {

            ll temp = min(now+nowu, n+1)-now;
            if (temp < 0) break;
            ans += (min(now+nowu , n+1)-now);

            now = now*10;
            nowu *= 10;
        }

        ini = ini*10+1;
    }
    cout << ans << endl;

    return 0;
}
