#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    ll n; cin >> n;

    if (n%2==1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = n /10;
    n /= 10;

    ll p = 5;
    while (p <= n) {
        ans += n / p;
        p = p*5;
    }
    cout << ans << endl;
}
