#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;

    vector<ll> list;
    for (int i = 0; i <= 60; i++) {
        for (int j = i+1; j <= 60; j++) {
            for (int k = j+1; k <= 60; k++) {
                ll tmp = (1LL<<i) + (1LL<<j) + (1LL<<k);
                list.push_back(tmp);
            }
        }
    }

    sort(list.begin(), list.end());

    for (int t = 0; t < T; t++) {
        ll n;
        cin >> n;

        int idx = upper_bound(list.begin(), list.end(), n) - list.begin();
        idx--;
        if (idx < 0) cout << -1 << endl;
        else cout << list[idx] << endl;
    }

    return 0;
}
