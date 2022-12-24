#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll g = gcd(a[0], a[1]);
    for (int i = 1; i < n; ++i) {
        g = gcd(g, a[i]);
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        a[i] /= g;
        ll cnt2 = 0;
        ll cnt3 = 0;
        while(a[i] != g) {
            if (a[i]%2 == 0) {
                a[i] /= 2;
                ans++;
            } else if (a[i]%3 == 0) {
                a[i] /= 3;
                ans++;
            } else {
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != 1) ans = -1;
    }

    cout << ans << endl;
    return 0;
}
