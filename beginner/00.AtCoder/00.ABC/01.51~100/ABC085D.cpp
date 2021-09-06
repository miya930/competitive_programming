#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll n, h;
    cin >> n >> h;
    ll ma = 0;
    priority_queue<ll> b;
    for (ll i = 0; i < n; ++i) {
        ll s, t;
        cin >> s >> t;
        ma = max(ma, s);
        b.push(t);
    }

    ll ans = 0;
    int hc = h;
    for (ll i = 0; i < 2*n; ++i) {
        if (!b.empty()) {
            ll tb = b.top();
            if (ma < tb) {
                hc -= tb;
                b.pop();
                ans++;
                if (hc <= 0) break;
            } else if (ma >= tb) {
                ans += (hc+ma-1) / ma;
                break;
            }  
        } else {
            ans += (hc+ma-1) / ma;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
