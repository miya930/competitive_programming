#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> isprime(10000010, true);

int main()
{
    ll n;
    cin >> n;

    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i <= 1000000; i++) {

        for (int j = i*2; j <= 1000000; j += i) {
            isprime[j] = false;
        }
    }
    vector<ll> primelist;
    for (int i = 2; i <= 1000000; i++) {
        if (isprime[i]) primelist.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < 170; i++) {
        ll a = primelist[i];
        
        for (int k = i + 2; k < primelist.size(); k++) {
            ll c = primelist[k];
            ll mul = a * a * c * c;

            if (mul > n) break;

            ll bma = n / mul;

            if (bma <= a) continue;

            int itr = upper_bound(primelist.begin(), primelist.end(), bma) - primelist.begin();
            
            ans = ans + min(k, itr) - (i + 1);
        }
    }

    cout << ans << endl;
    return 0;
}
