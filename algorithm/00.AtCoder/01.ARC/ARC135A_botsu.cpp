#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    ll x;
    cin >> x;

    queue<ll> que;
    que.push(x);
    ll ans = 1;

    if (x/2 == 1) {
        cout << x%mod << endl;
        return 0;
    }

    while(!que.empty()) {
        ll xx = que.front();
        que.pop();
        ll x1 = xx/2;
        ll x2 = (xx+1)/2;


        if (x1 != 1) {

            if (x1/2 == 1) {
                ans *= x1;
                ans %= mod;
            }
            if (x2/2 == 1) {
                ans *= x2;
                ans %= mod;
            }
            que.push(x1); que.push(x2);
        } 
    }
    cout << ans << endl;

    return 0;
}
