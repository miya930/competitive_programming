#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
const ll INF = 1e18;

int gcd(ll n, ll m) {
    if (m == 0) return n;
    else return gcd(m, n % m);
}

int main()
{
    int n; cin >> n;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    ll ans = INF;

    vector<int> vec(51, 1);
    vector<int> prime;

    vec[0] = 0; vec[1] = 0;
    for (int i = 2; i < 51; ++i) {
        for (int j = i * 2; j < 51; j += i) {
            vec[j] = 0;
        }
    }

    for (int i = 0; i < 51; ++i) {
        if (vec[i] == 1) prime.push_back(i);
    }

    for (int bits = 0; bits < (1 << prime.size()); ++bits) {
        ll temp = 1;
        for (int i = 0; i < prime.size(); ++i) {
            if (bits & (1 << i)) {
                temp *= prime[i];
            }
        }
        bool flg = false;
        for (int i = 0; i < n; ++i) {
            if (gcd(temp, x[i]) == 1) {
                flg = true;
                break;
            }
        }
        if (!flg) ans = min(ans, temp);
    }
    cout << ans << endl;

}
