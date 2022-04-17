/* 浮動小数を使うと誤差で誤った答えになりそうなので、すべて整数で計算
 * y - y1 = (y1 - y2)/(x1 - x2) * (x - x1) ⇔ (y - y1) * (x1 - x2) = (y1 - y2) * (x - x1);
 *
 * 同じ直線を何個もカウントしないように map で記録.
 * ax + by + c = 0
 * (y1 - y2)*x + (x1 - x2) * y + (y1 - y2)*x1 - y1*(x1 - x2) = 0;
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int func(int x1, int y1, int x2, int y2, int xt, int yt) {
    int left = (yt - y1)*(x1 - x2);
    int right = (y1 - y2)*(xt - x1);
    if (left == right) return true;
    else return false;
}

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> x(n), y(n);
    map<pair<pair<ll,ll>,ll>, ll> mp;
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll x1 = x[i], y1 = y[i];
            ll x2 = x[j], y2 = y[j];

            ll a = y[i] - y[j];
            ll b = x[i] - x[j];
            ll c = (y[i] - y[j])*x[i] - y[i]*(x[i] - x[j]);

            ll g = gcd(a, gcd(b, c));
            a /= g; b /= g; c /= g;

            if (mp[{{a, b}, c}] != 0) continue;
            mp[{{a, b}, c}]++;

            int cnt = 2;
            for (int l = 0; l < n; ++l) {
                if (i == l || j == l) continue;

                if (func(x1, y1, x2, y2, x[l], y[l])) cnt++;
            }
            if (cnt >= k) ans++;
        }
    }

    if (k == 1) cout << "Infinity" << endl;
    else cout << ans << endl;

    return 0;
}



