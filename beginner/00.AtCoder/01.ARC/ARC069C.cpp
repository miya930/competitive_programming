#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;

    if (2*n > m) {
        cout << m/2 << endl;
        return 0;
    }
    
    ll ans = n;
    m -= 2*n;
    ans += m/4;
    cout << ans << endl;
}
