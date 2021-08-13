#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll ma = 1LL << 60;
const ll s_ma = 1000000007;

vector<bool> is_prime(s_ma, true);
vector<bool> is_prime_small(s_ma, true);

int main()
{
    ll a, b;
    cin >> a >> b;

    is_prime_small[0] = is_prime_small[1] = false;
    for (int i = 2; (ll)i*i < b; ++i) {
        for (int j = 2*i; (ll)j*j < b; j += i) is_prime_small[j] = false;
        for (ll j = max(2LL, (a + i - 1)/i*i); j < b; j += i) is_prime[j-a] = false;
    }

    int ans = 0;
    for (int i = a; i < b; ++i) {
        if (is_prime[i-a]) ans++;
    }
    
    cout << ans << endl;
    return 0;
}
