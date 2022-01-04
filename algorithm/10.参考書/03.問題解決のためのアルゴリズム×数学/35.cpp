#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    /**
     * 1:2頂点の距離 < max(r1, r2) - min(r1, r2)
     * 2:2頂点の距離 = max(r1, r2) - min(r1, r2)
     * 3:
     * 4:2頂点の距離 = r1 + r2
     * 5:2頂点の距離 > r1 + r2
     */

    vector<ll> x(2), y(2), r(2);
    for (int i = 0; i < 2; ++i) cin >> x[i] >> y[i] >> r[i];

    ll dx = x[0] - x[1];
    ll dy = y[0] - y[1];
    ll dist = dx*dx + dy*dy;
    ll tmp = max(r[0], r[1]) - min(r[0], r[1]);
    ll mi = tmp*tmp;
    ll tmp2 = r[0] + r[1];
    ll pl = tmp2*tmp2;
    
    int ans = 0;
    if (dist < mi) ans = 1;
    else if (dist == mi) ans = 2;
    else if (dist > mi && dist < pl) ans = 3;
    else if (dist == pl) ans = 4;
    else ans = 5; 

    cout << ans << endl;
    return 0;
}
