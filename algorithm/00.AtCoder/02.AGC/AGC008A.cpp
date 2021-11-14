/**
   created: 23.10.2021 19:39:11
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll infl = 1LL<<60;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    ll x, y;
    cin >> x >> y;

    ll ans = infl;

    ll ry = -y, rx = -x;
    if (x <= y) chmin(ans, y-x);
    if (rx <= y) chmin(ans, y-rx+1);
    if (x <= ry) chmin(ans, ry-x+1);
    if (rx <= ry) chmin(ans, ry-rx+2);

    cout << ans << endl;

    return 0;
}
