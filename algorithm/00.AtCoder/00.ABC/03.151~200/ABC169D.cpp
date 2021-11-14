#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

vector<pair<ll, ll> > func(ll n) {
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
    ll n;
    cin >> n;

    ll ans = 0;
    vector<pair<ll, ll> > cnt = func(n);
    vector<ll> div;
    map<ll, ll> mp;

    for (ll i = 0; i < cnt.size(); ++i) {
        if (mp[cnt[i].first]) continue;
        ll temp = 1;
        ll count = cnt[i].second;
        ll res = 1;
        while (count >= res) {
            count -= res;
            res++;
            temp *= cnt[i].first;
            if (mp[temp]) continue;
            mp[temp]++;
            div.push_back(temp);
        }
    }
    sort(div.begin(), div.end());

    for (int i = 0; i < div.size(); ++i) {
        if (n / div[i] == 0) continue;
        ans++;
        n /= div[i];
    }
    cout << ans << endl;
}
