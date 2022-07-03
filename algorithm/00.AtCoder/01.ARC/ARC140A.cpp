#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;

    int ans = inf;
    for (int l = 1; l <= n; ++l) {
        if (n%l != 0) continue;

        int now = 0;
        for (int i = 0; i < l; i++) {
            map<int,int> mp;
            int mx = 0;
            for (int j = i; j < n; j += l) mx = max(mx, ++mp[s[j]]);
            now += (n/l - mx);
        }
        if (now <= k) ans = min(ans, l);
    }

    cout << ans << endl;
    return 0;
}
