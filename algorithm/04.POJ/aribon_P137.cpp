#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int,int> mp, mp2;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    int sz = mp.size();

    int r = 0;
    int ans = inf;
    for(int l = 0; l < n; l++) {
        while(r < n || mp2.size() < sz) {
            mp2[a[r]]++;
            r++;
        }
        ans = min(ans, r - l);
        if (r <= l) r++;
        mp2[a[l]]--;
        if (mp2[a[l]] == 0) mp2.erase(a[l]);
    }

    cout << ans << endl;
    return 0;
}
