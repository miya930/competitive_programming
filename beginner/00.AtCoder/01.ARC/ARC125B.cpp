#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int mod = 998244353;

int main()
{
    ll n; 
    cin >> n;

    int ma = (int)sqrt(n);

    int ans = 0;
    for (int i = 1; i <= ma; ++i) {
        ll a = n / i;
        if (a%2 != i%2) a--;
        ll temp = (a-i)/2+1;
        temp %= mod;
        ans = (ans + temp) % mod;
    }
    
    cout << ans << endl;

}
