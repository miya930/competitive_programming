#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> vec;
    for (int i = 0; i < 61; ++i) {
        if ((n>>i)&1) {
            vec.push_back(i);
        }
    }

    vector<ll> ans;
    for (int i = 0; i < (1<<vec.size()); ++i) {
        ll tmp = 0;
        for (int j = 0; j < vec.size(); ++j) {
            if ((i>>j)&1) {
                tmp += (1LL<<vec[j]);
            }
        }
        ans.push_back(tmp);
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << ans[i] << endl;

    return 0;
}
