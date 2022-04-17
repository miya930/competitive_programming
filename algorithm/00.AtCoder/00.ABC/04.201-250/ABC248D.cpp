#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> mp(200010);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        mp[a[i]].push_back(i);
    }


    int Q; cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;

        if (l == r && a[r] == x) {
            cout << 1 << endl;
            continue;
        }
        
        int itr1 = upper_bound(mp[x].begin(), mp[x].end(), r) - mp[x].begin();
        int itr2 = lower_bound(mp[x].begin(), mp[x].end(), l) - mp[x].begin();
        
        if (mp[x].size() == 0) cout << 0 << endl;
        else cout << itr1 - itr2 << endl;
    }


    return 0;
}
