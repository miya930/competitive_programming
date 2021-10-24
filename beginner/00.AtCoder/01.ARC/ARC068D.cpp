/**
   created: 18.10.2021 21:24:21
**/
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[a[i]]++;

    int even_cnt = 0;
    for (auto x : mp) {
        if (x.second > 1 && x.second%2 == 1) {
            x.second = 1;
        } else if (x.second > 1  && x.second%2 == 0) {
            even_cnt++;
        }
    }

    int ans = mp.size();
    if (even_cnt%2 == 1) ans--;

    cout << ans << endl;

    return 0;
}
