#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const ll infl = 1LL << 60;

void chmax(ll &a, ll b) { a = max(a, b);};

int main()
{
    int n;
    cin >> n;
    vector<P> pos(n);

    for (int i = 0; i < n; ++i) cin >> pos[i].first >> pos[i].second;

    map<P, int> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ll diffx = pos[j].first - pos[i].first;
            ll diffy = pos[j].second - pos[i].second;

            if (mp[P(-diffx, -diffy)] > 0) {
                diffx = -diffx;
                diffy = -diffy;
            }

            mp[P(diffx, diffy)]++;
        }
    }

    ll ma = 0;
    for (auto x : mp) chmax(ma, x.second);
    
    cout << n - ma << endl;
   

    return 0;
}
