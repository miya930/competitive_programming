#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 998244353;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.rbegin(), a.rend());
    ll ans = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] * a[i];
        ans %= mod;
        ans += a[i] * sum;
        sum *= 2;
        sum += a[i];
        sum %= mod;
        ans %= mod;
    }
    cout << ans << endl;
    
}
