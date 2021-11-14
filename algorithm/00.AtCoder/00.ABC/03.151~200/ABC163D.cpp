#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll ans = 0;

    vector<ll> vec(n+2, 0);
    for (int i = 0; i <= n; ++i) vec[i+1] = vec[i] + i;

    for (int i = k; i <= n+1; ++i) {
        ll h = vec[n+1] - vec[n+1-i];
        ll l = vec[i];
        ans += (h-l+1);
        ans %= mod;
    }

    cout << ans << endl;
    return 0;

}
