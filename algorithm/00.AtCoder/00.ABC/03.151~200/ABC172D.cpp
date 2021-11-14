#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> vec(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            vec[j]++;
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) ans += i*vec[i];

    cout << ans << endl;
    return 0;
}


/***
 * 想定解
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll n; cin >> n;
    
    ll ans = 0;
    for (ll x = 1; x <= n; ++x) {
        ll y = n/x;
        ans += y*(y+1)/2*x;
    }
    cout << ans << endl;
}
