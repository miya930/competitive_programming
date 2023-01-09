#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    ll k;
    cin >> k;

    vector<pair<ll,ll>> vec = prime_factorization(k);
    ll ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        ll t1 = vec[i].first;
        ll t2 = vec[i].second;
        
        ll tmp = 0;
        ll s = 0;
        while(t2 - tmp > 0) {
            s += t1;
            ll cnt = 0;
            ll tmp2 = s;
            while(tmp2%t1 == 0) {
                cnt++;
                tmp2 /= t1;
            }
            tmp += cnt;
        }
        ans = max(ans, s);
    }

    cout << ans << endl;
    return 0;
}
