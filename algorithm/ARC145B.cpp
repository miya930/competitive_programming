#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans = 0;
    ll div = n / a;
    ll mo = n % a;

    if (a > b) {
        ans += ((div-1) * (b + 1));
        ans += min(b, mo);
    } else {
        ans += ((div-1) * (a-b));
        ans += (max(mo - b, 0LL));
    }
    
    cout << ans << endl;

    return 0;
}
