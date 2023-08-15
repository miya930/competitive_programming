#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll infl = 1e18+100;

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = -infl;

    ans = max(ans, a*d);
    ans = max(ans, a*c);
    ans = max(ans, b*c);
    ans = max(ans, b*d);

    cout << ans << endl;

    return 0;
}
