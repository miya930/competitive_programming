#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ll k = i;
        for (ll d = 2; d*d <= k; d++) {
            while(k%(d*d) == 0) k /= (d*d);
        }
        for (ll d = 1; k*d*d <= n; d++) ans++;
    }
    cout << ans << endl;
    return 0;
}
