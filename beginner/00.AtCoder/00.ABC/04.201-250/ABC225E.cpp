#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

struct frac {
    ll a, b;
    frac(ll _a = 0, ll _b = 1): a(_a), b(_b) {
        if (b == 0) {a = 1; return;}
        if (b < 0)  a = -a, b = -b;
        ll g = gcd(a, b);
        a /= g, b /= g;
    }

    bool operator<(const frac& x) const {
        return a*x.b < x.a*b;
    }

    bool operator == (const frac& x) const {
        return a==x.a && b==x.b;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
    vector<frac> lf(n), rf(n);
    for (int i = 0; i < n; ++i) lf[i] = frac(x[i]-1, y[i]);
    for (int i = 0; i < n; ++i) rf[i] = frac(x[i], y[i]-1);
    map<frac, int> mp;
    for (int i = 0; i < n; ++i) mp[lf[i]] = mp[rf[i]] = 0;
    int m = 0;
    for (auto&& p : mp) p.second = m++; 
    vector<P> d;
    for (int i = 0; i < n; ++i) d.emplace_back(mp[rf[i]], mp[lf[i]]);
    sort(d.begin(), d.end());

    int mx = -1, ans = 0;
    for (auto [r, l] : d) {
        if (l >= mx) mx = r, ++ans;
    }
    cout << ans << endl;

    return 0;
}
