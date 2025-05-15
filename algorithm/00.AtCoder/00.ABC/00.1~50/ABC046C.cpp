#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n), a(n);
    for (int i = 0; i < n; i++) cin >> t[i] >> a[i];

    ll cr = 1, cl = 1;
    for (int i = 0; i < n; i++) {
        ll r = t[i];
        ll l = a[i];

        if (cr <= r && cl <= l) {
            cr = r;
            cl = l;
        } else if (cr <= r && cl > l) {
            ll tmp = (cl + l - 1) / l;
            cr = r * tmp;
            cl = l * tmp;
        } else if (cr > r && cl <= l){
            ll tmp = (cr + r - 1) / r;
            cr = r * tmp;
            cl = l * tmp;
        } else if ((cr > r && cl > l)) {
            ll tmpr, tmpl;
            tmpr = (cr + r - 1) / r;
            tmpl = (cl + l - 1) / l;
            ll tmp;
            if (tmpr > tmpl) tmp = tmpr;
            else tmp = tmpl;

            cr = r * tmp;
            cl = l * tmp;
        }
    }

    cout << cr + cl << endl;

    return 0;
}
