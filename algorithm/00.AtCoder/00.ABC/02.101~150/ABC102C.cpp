#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (int a = 1; a <= n; ++a) {
        if (2*a % k != 0) continue;
        
        ll low = (a+1+k-1)/k;
        ll high = (n+a)/k;
        ans = ans + (high - low + 1)*(high - low + 1);
    }

    cout << ans << endl;
    return 0;
}
