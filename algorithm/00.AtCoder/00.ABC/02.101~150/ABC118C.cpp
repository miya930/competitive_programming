#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll n, ll m) {
    
    if(m == 0) return n;
    return gcd(m, n%m);
}

int main(void)
{
    ll N;
    cin >> N;
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        ll A; cin >> A;
        ans = gcd(ans, A);
    }
    cout << ans << endl;
}
