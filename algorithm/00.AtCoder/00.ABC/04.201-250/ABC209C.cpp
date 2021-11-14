#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];

    sort(c.begin(), c.end());

    ll ans = c[0];
    ll sum = 1;
    for (int i = 1; i < n; ++i) {
        ans *= (c[i]-sum);
        ans %= mod;
        sum++;
    }
    cout << ans << endl;
}
