#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b;
vector<bool> isprimes(1002000, true), isprime;

int main()
{
    cin >> a >> b;
    isprime.assign(1001000, true);

    for (ll i = 2; i*i < b; ++i) {
        if (isprimes[i] == false) continue;
        for (ll j = i*2; j*j < b; j += i) isprimes[j] = false;
        for (ll j = max(2LL, ((a+i-1)/i)*i); j < b; j += i) isprime[j-a] = false; /* (a+i-1)/i * i ：a以上で最小のiの倍数 */
    }

    int ans = 0;
    for (ll i = 0; i < b-a; ++i) {
        if (isprime[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}
