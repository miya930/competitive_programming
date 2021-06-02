#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1000000007;
typedef long long ll;

int main()
{
    int w, h;
    cin >> w >> h;

    ll ans = 1;
    ll n = w + h - 2;
    ll k = w - 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
        ans %= MOD;
    }
    for (int i = 1; i <= (n - k); ++i) ans /= i;
    for (int i = 1; i <= k; ++i) ans /= i;
    
    cout << ans << endl;
}
