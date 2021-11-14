#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll x, y;
    extGCD(a, b, x, y);

    vector<ll> ans(4, 0);

    int i_x = 0, i_y = 2;
    if (x < 0) i_x = 1;
    if (y < 0) i_y = 3;

    ans[i_x] = abs(x);
    ans[i_y] = abs(y);

    for (int i = 0; i < 4; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
