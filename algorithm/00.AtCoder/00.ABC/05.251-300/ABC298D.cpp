#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

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

int main()
{
    int Q;
    cin >> Q;

    ll ans = 1;
    deque<ll> que(1,1);

    for (int q = 0; q < Q; q++) {
        int t;
        cin >> t;

        if (t == 1) {
            int x;
            cin >> x;

            ans = (ans * 10 + x) % mod;
            que.push_back(x);

        } else if (t == 2) {
            ll tmp = que.front();

            ans -= (tmp * modpow(10LL, (ll)(que.size()-1), mod)) % mod;
            ans = (ans + mod) % mod;

            que.pop_front();
        } else {
            cout << ans % mod << endl;
        }
    }

    return 0;
}
