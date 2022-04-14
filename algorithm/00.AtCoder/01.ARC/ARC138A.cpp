#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = -i;
    }
    sort(a.begin(), a.end());

    int mx = -inf, ans = inf;
    for (auto [v, i]:a) {
        i = -i;
        if (i < k) mx = max(mx, i);
        else ans = min(ans, i-mx);
    }

    if (ans != inf) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}
