#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    ll n, w;
    cin >> n >> w;
    vector<pair<ll, ll>> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;

    sort(vec.rbegin(), vec.rend());

    ll ans = 0;
    ll cnt = 0;
    while (1) {
        ll gram = vec[cnt].second;
        ll temp = min(w, gram);
        w -= temp;
        ans += vec[cnt].first*temp;
        cnt++;
        if (w == 0 || cnt == n) break;
    }

    cout << ans << endl;

    return 0;
}
