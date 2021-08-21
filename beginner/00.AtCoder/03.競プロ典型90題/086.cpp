#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<ll> x(q), y(q), z(q), w(q);

    for (int i = 0; i < q; ++i) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
        x[i]--; y[i]--; z[i]--;
    }

    ll ans = 1;
    for (int i = 0; i < 60; ++i) {
        ll temp = 0;
        for (int bit = 0; bit < (int)1<<n; ++bit) {
            bool flag = true;
            for (int j = 0; j < q; ++j) {
                if ((bit>>x[j]&1 | bit>>y[j]&1 | bit>>z[j]&1) != (w[j]>>i&1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                temp++;
                temp %= mod;
            }
        }
        ans *= temp;
        ans %= mod;
    }

    cout << ans << endl;

}
