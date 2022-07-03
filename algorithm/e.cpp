#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, Q, x;
    cin >> n >> Q >> x;

    vector<ll> w(n), k(Q);
    for (ll i = 0; i < n; ++i) cin >> w[i];
    for (ll i = 0; i < Q; ++i) cin >> k[i];

    vector<int> vec;
    vector<ll> sum(n+1);
    vector<int> seen(n,0);
    ll ini = 0;
    for (int i = 0; i < n; ++i) sum[i+1] = sum[i] + w[i];
    while(1) {
        seen[ini]++;
        if (seen[ini] > 2) break;
        ll s = sum[n] - sum[ini];
        int en;
        if (x - s < 0) {
            for (int i = ini+1; i < n; ++i) {
                ll t = sum[i] - sum[ini];
                if (t >= x) {
                    en = i;
                    break;
                }
            }
            vec.push_back(en);
            ini = en;
        } else {
            ll xx = x - s;
            ll ss = n - ini;
            ll div = xx / sum[n];
            ll mod = xx % sum[n];
            ss += n * div;

            for (int i = 0; i < n; ++i) {
                ll t = sum[i];
                if (t >= mod) {
                    en = i;
                    break;
                }
            }
            vec.push_back(ss + en);
            ini = en;
        }
    }

    vector<int> start, cycle;
    for (int i = 0; i < (int)vec.size(); ++i) {
        if (seen[i] == 1) start.push_back(vec[i]);
        else break;
    }

    for (int i = (int)start.size(); i < (int)start.size() + ((int)vec.size() - (int)start.size())/2; ++i) {
        cycle.push_back(vec[i]);
    }

    for (int i = 0; i < Q; ++i) {
        if (k[i] <= start.size()) {
            cout << start[k[i]-1] << endl;
        } else {
            ll itr = k[i] - 1 - start.size();
            itr %= cycle.size();
            cout << cycle[itr] << endl;
        }
    }

    return 0;
}
