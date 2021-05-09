#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<pair<ll, ll> > prime_factorize(ll n) {
    vector<pair<ll, ll> > res;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ll ex = 0;
        while(n%i==0) {
            ex++;
            n /= i;
        }
        
        res.push_back({i, ex});
    }

    if (n != 1) res.push_back({n, 1});
    return res;
}

int main()
{
    ll N;
    cin >> N;
    const auto &res = prime_factorize(N);
    cout << N << ":";
    for (auto p : res) {
        for (int i = 0; i < p.second; ++i) cout << " " << p.first;
    }
    cout << endl;
}
