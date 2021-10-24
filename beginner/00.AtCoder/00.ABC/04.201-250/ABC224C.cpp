#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll> > pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                pair<ll, ll> diff12, diff13;
                diff12.first = (pos[j].first-pos[i].first);
                diff12.second = (pos[j].second-pos[i].second);
                diff13.first = (pos[k].first-pos[i].first);
                diff13.second = (pos[k].second-pos[i].second);
                
                bool para = false;

                if (diff12.first == 0 && diff13.first == 0) para = true;

                if (para || (diff12.first*diff13.second == diff12.second*diff13.first)) continue;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
