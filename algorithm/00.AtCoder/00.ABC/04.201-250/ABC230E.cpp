#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;

    ll ans = 0;
    ll mul = 1;
    while (mul*mul <= n) {
        ans += ((n/mul - n/(mul+1))*mul);
        mul++;
    }

    ll k = 0;
    for (ll i = 0; i*i <= n; ++i) k = i;

    for (int i = 1; i <= n / (k+1); ++i) ans += n/i;

    cout << ans << endl;

}
