#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll, ll> > res;

    for (ll i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ll ex = 0;

        while (n % i == 0) {
            ex++;
            n /= i;
        }
        res.push_back({ i, ex });
    }

    if (n != 1)  res.push_back({ n, 1 });

    return res;
}

int main()
{
    ll n; cin >> n;

    vector<pair<ll, ll> > vec = prime_factorize(n);

    ll sum = 0, ans = 0;
    for (auto x : vec) {
        sum += x.second;
    }

    while (sum > 1) {
        ans++;
        sum = (sum+1)/2;
    }
    cout << ans << endl;

}
