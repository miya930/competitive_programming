#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> func(ll n) {
    vector<ll> res;
    for (int i = 1; i*i <= n; ++i) {
        if (n%i != 0) continue;
        res.push_back(i);

        if (n/i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> vec = func(m);
    int size = vec.size();

    ll ans;
    for (int i = 0; i < size; ++i) {
        if (vec[i] >= n) {
            ans = m/vec[i];
            break;
        }
    }
    
    cout << ans << endl;
    return 0;
}
