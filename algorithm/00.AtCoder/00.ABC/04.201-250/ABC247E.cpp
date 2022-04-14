#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int>> list;
    bool fx = false, fy = false;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x || a[i] < y) {
            if (fx == true && fy == true) {
                list.push_back(vec);
            }
            vec.clear();
            fx = false; fy = false;
        } else {
            if (a[i] == x) fx = true;
            if (a[i] == y) fy = true;
            vec.push_back(a[i]);
        }
    }
    if (fx == true && fy == true) list.push_back(vec);

    ll ans = 0;
    for (auto li : list) {
        int si = li.size();

        int r = 0;
        map<int,int> mp;
        ll tmp = 0;
        for (int l = 0; l < si; ++l) {
            while(r < si && (mp[x] == 0 || mp[y] == 0)) {
                if (li[r] == x) mp[x]++;
                else if (li[r] == y) mp[y]++;
                r++;
            }
            if (mp[x] != 0 && mp[y] != 0)tmp += (si-r+1);
            if (li[l] == x) mp[x]--;
            else if (li[l] == y) mp[y]--;
            if (l == r) r++;
        }

        ans += tmp;
    }

    cout << ans << endl;
    return 0;
}
