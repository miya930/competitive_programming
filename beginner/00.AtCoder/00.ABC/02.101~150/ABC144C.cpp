#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1000000000000000000LL;

vector<ll> func(ll n) {
    vector<ll> res;
    for (ll i = 1; i*i<=n; ++i) {
        if (n%i!=0) continue;
        res.push_back(i);
        if (n/i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll n;
    cin >> n;    

    vector<ll> div = func(n);

    ll ans = INF;
    for (int i = 0 ; i < div.size(); ++i) {
        ans = (ll)min(ans, (div[i]-1) + (n/div[i] - 1));
    }
    cout << ans << endl;
}
