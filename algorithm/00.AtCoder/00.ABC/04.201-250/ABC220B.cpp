#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll todec(ll a, ll k) {
    ll res = 0;
    ll i = 1;
    while (a > 0) {
        res += (a%10)*i;
        i *= k;
        a /= 10;
    }
    return res;
}

int main()
{
    ll k, a, b;
    cin >> k >> a >> b;

    ll ans = todec(a, k) * todec(b, k);
    cout << ans << endl;

    return 0;
}
