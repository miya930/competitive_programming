#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll, ll> > vec;

ll gcd(ll n, ll m) {
    if (m == 0) return n;
    else return gcd(m, n % m);
}

vector<pair<ll, ll> > prime_fact(ll n) {
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
    if (n != 1) res.push_back({ n, 1 });
    return res;
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ma = gcd(a, b);
    vec = prime_fact(ma);

    cout << 1 + vec.size() << endl;

}
