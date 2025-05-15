#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a, f;
ll n, k;

bool check(ll mid) {
    vector<ll> aa = a, ff = f;
    ll mm = mid;
    ll kk = k;
    for (ll i = 0; i < n; i++) {
        ll mul = aa[i] * ff[i];
        if (mul <= mm) continue;
        ll tmp = mm / ff[i];
        ll dif = aa[i] - tmp;
        kk -= dif;
    }
    if (kk < 0) return false;
    else return true;
}

int main()
{
    cin >> n >> k;
    a.resize(n);
    f.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> f[i];
    sort(a.rbegin(), a.rend());
    sort(f.begin(), f.end());

    ll r = 1LL << 60, l = -1;
    while(r-l > 1) {
        ll m = (r + l) / 2;
        if (check(m)) r = m;
        else l = m;
    }

    cout << r << endl;

    return 0;
}
