#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> div(ll n) {
    vector<ll> res;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        res.push_back(i);
        if (n / i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());
    
    return res;
}

int main()
{
    ll n;
    cin >> n;

    vector<ll> ans = div(n);
    for (ll i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

    return 0;
}
