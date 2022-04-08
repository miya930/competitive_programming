#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1000000007;

vector<pair<int,int>> func(ll n) {
    vector<pair<int,int>> res;
    for (int i = 2; i*i <= n; ++i) {
        if (n%i != 0) continue;
        int ex = 0;
        while(n%i == 0) {
            ex++;
            n /= i;
        }
        res.push_back({i, ex});
    }
    if (n != 1) res.push_back({n, 1});

    return res;
}

template <class T> T modpow(T n, T m, T mo) {
    T res = 1;
    while(m > 0) {
        if (m & 1) res = res * n % mo;
        m >>= 1;
        n *= n;
        n %= mo;
    }
    return res;
}

template <class T> T moddiv(T n, T mo) {
    return modpow(n, mo-2, mo);
}

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        vector<pair<int,int>> vec = func(a[i]);

        for (auto x : vec) {
            if (mp[x.first] < x.second) mp[x.first] = x.second;
        }
    }

    ll tmp = 1;
    for (auto x : mp) {
        for (int i = 1; i <= x.second; ++i) {
            tmp *= x.first;
            tmp %= mod;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += tmp * moddiv(a[i], mod);
        ans %= mod;
    }

    cout << (ans+mod)%mod << endl;
    return 0;
}
