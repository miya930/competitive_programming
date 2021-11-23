#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    ll lmax = l[0], lmin = l[0], rmax = r[0], rmin = r[0];
    for (int i = 0; i < n; ++i) {
        lmax = max(lmax, l[i]);
        lmin = min(lmin, l[i]);
        rmax = max(rmax, r[i]);
        rmin = min(rmin, r[i]);

        if (lmax <= rmin) {
            cout << 0 << endl;
        } else {
            cout << (lmax-rmin+1)/2 << endl;
        }

    }

    return 0;
}
