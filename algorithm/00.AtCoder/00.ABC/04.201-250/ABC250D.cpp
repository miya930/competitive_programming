#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;

    vector<bool> isprime(1010000, true);
    isprime[0] = isprime[1] = false;

    for (ll i = 2; i <= 1000000; ++i) {
        for (ll j = i*2; j <= 1000000; j+=i) {
            isprime[j] = false;
        }
    }
    vector<ll> sum(1000000, 0);
    for (int i = 0; i < 1000000; ++i) {
        int tmp = 0;
        if (isprime[i]) tmp++;
        sum[i+1] = sum[i] + tmp;
    }

    ll ans = 0;
    for (ll q = 2; q <= 1000000; ++q) {
        if (!isprime[q]) continue;
        ll tmp = q*q*q;
        ll tmp2 = n/tmp;
        if (tmp2 >= q) tmp2 = q-1;
        ans += sum[tmp2+1];
    }

    cout << ans << endl;
    return 0;
}
