/**
   created: 09.10.2021 13:33:37
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] /= 2;
    }

    ll lc = a[0];
    for (int i = 0; i < n; ++i) {
        lc = lc / gcd(lc, a[i]) * a[i];
    }

    for (int i = 0; i < n; ++i) {
        if ((lc / a[i])%2 == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    ll ans = m / lc;
    ans = (ans + 1) / 2;
    cout << ans << endl;

    return 0;
}
