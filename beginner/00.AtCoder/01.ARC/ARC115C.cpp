#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 100010;

vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= n; ++a) {
        if (n % a != 0) continue;
        ll ex = 0;
        while (n % a == 0) {
            n /= a;
            ex++;
        }
        res.push_back({ a, ex });
    }
    if (n != 1) res.push_back({ n, 1 });
    return res;
}


int main()
{
    int n;
    cin >> n;


    for (int i = 1; i <= n; ++i) {
        const auto& pf = prime_factorize(i);
        ll res = 1;
        for (auto p : pf) res += p.second;
        cout << res << " ";
    }
    cout << endl;
}
