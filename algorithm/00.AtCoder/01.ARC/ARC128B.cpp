#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int t;
    cin >> t;
    while (t > 0) {
        t--;
        vector<int> a(3);
        for (int i = 0; i < 3; ++i) cin >> a[i];

        sort(a.rbegin(), a.rend());

        int ans = inf;
        for (int i = 0; i < 3; ++i) {
            int s = max(a[i], a[(i+1)%3]);
            int t = min(a[i], a[(i+1)%3]);
            if ((s-t)%3 != 0) continue;
            ans = min(ans, s);
        }
        
        if (ans != inf) cout << ans << endl;
        else cout << -1 << endl;
    }

    return 0;
}
