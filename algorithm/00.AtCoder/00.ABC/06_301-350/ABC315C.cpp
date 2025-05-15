#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, int>> pa(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> pa[i].second >> pa[i].first;
        mp[pa[i].second]++;
    }
    sort(pa.rbegin(), pa.rend());

    ll ma = 0;
    if (pa[0].second != pa[1].second) {
        ma = max(ma, pa[0].first+pa[1].first);
        int cur = 2;
        while(cur < n) {
            if (pa[0].second == pa[cur].second) {
                ma = max(ma, pa[0].first + pa[cur].first/2);
                break;
            }
            cur++;
        }
    } else {
        ma = max(ma, pa[0].first+pa[1].first/2);
        int cur = 2;
        while(cur < n) {
            if (pa[0].second != pa[cur].second) {
                ma = max(ma, pa[0].first + pa[cur].first);
                break;
            }
            cur++;
        }
    }
    cout << ma << endl;
    return 0;
}
