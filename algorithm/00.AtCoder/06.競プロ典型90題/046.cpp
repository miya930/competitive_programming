/**
 * 046  - I Love 46 (Åö3)
 * https://atcoder.jp/contests/typical90/tasks/typical90_at
 * 
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)

const ll mod = 46;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    map<ll, ll> mpa, mpb, mpc;

    rep(i, n) mpa[a[i]%mod]++;
    rep(i, n) mpb[b[i]%mod]++;
    rep(i, n) mpc[c[i]%mod]++;
    
    ll ans = 0;
    for (int i = 0; i < mod; ++i) {
        for (int j = 0; j < mod; ++j) {
            for (int k = 0; k < mod; ++k) {
                if (mpa[i] != 0 && mpb[j] != 0 && mpc[k] != 0) {
                    if ((i+j+k)%mod == 0) ans += mpa[i]*mpb[j]*mpc[k];
                }
            }
        }
    }
    cout << ans << endl;
}
