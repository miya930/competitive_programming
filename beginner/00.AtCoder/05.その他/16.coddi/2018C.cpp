#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

template<class T> vector<pair<T, T> > prime_factorization(T n) {
    vector<pair<T, T> > res;
    for (T i = 2; i * i <= n; ++i) {
        if (n%i != 0) continue;
        T ex = 0;
        while (n%i == 0) {
            ex++;
            n /= i;
        }
        res.push_back(make_pair(i, ex));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    ll n, p;
    cin >> n >> p;

    vector<pair<ll, ll> > vec = prime_factorization(p);
    vector<ll> gc;

    for (int i = 0; i < (int)vec.size(); ++i) {
        ll v = vec[i].first;
        ll ex = vec[i].second;
        
        ll add = ex / n;
        for (int j = 0; j < add; ++j) gc.push_back(v);
    }

    ll ans = 1;
    for (int i = 0; i < (int)gc.size(); ++i) {
        ans *= gc[i];
    }

    cout << ans << endl;

    return 0;
}
