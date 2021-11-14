#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;

    ll div = n/k;
    ll ans = min(n - div*k, (ll)abs(n-div*k-k));
    cout << ans << endl;
}
