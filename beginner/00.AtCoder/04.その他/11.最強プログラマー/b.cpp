// https://atcoder.jp/contests/jsc2019-qual/tasks/jsc2019_qual_b
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; ++i)

ll modfunc(ll k) {
    ll res = k*(k+1)/2%mod;
    return res;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<pair<ll, ll> > vec(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] > a[j]) vec[i].first++;
        }
        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]) vec[i].second++;
        }
    }

    ll ans = 0;

    rep(i, n) {
        ans = ans + modfunc(k-1)*vec[i].first%mod+modfunc(k)*vec[i].second%mod;
        ans %= mod;
    }

    cout << (ans+mod)%mod << endl;
}
