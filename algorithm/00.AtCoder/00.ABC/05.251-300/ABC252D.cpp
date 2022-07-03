#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, vector<int>> mp;
    for (int i = n-1; i >= 0; --i) {
        mp[a[i]].push_back(i);
    }

    ll ans = (ll)n*(n-1)*(n-2)/6;

    for (auto x : mp) {
        ll si = x.second.size();
        ll tmp1 = 0, tmp2 = 0;
        if (si >= 3) tmp1 = si*(si-1)*(si-2)/6;
        if (si >= 2) tmp2 = si*(si-1)/2*(n-si);
        
        ans -= (tmp1+tmp2);
    }
    
    cout << ans << endl;
    return 0;
}
