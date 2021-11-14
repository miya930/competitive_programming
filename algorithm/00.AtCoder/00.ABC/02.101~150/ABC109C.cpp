#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m)
{
    if (m == 0) return n;
    return gcd(m, n%m);
}

int main(void)
{
    ll N, X;
    cin >> N >> X;

    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll x;
        cin >> x;
        ans = gcd(ans, abs(X-x));
    }
    cout << ans << endl;
}
