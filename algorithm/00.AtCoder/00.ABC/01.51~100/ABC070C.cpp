/**
   created: 23.10.2021 09:43:24
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

template<class T> T lcm(T n, T m) {
    return n / gcd(n, m) * m;
}

int main()
{
    int n;
    cin >> n;
    vector<ll> t(n);
    for (int i = 0; i < n; ++i) cin >> t[i];

    ll g = 1;
    ll l = 1;
    for (int i = 0; i < n; ++i) {
        l = lcm(t[i], l);
    }

    cout << l << endl;

    return 0;
}
