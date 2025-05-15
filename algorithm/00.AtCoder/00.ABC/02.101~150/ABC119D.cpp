#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int a, b, Q;
    cin >> a >> b >> Q;
    vector<ll> s(a), t(b);
    for (int i = 0; i < a; i++) cin >> s[i];
    for (int i = 0; i < b; i++) cin >> t[i];

    for (int q = 0; q < Q; q++) {
        ll x;
        cin >> x;

        auto itr1 = lower_bound(s.begin(), s.end(), x);
        auto itr2 = lower_bound(t.begin(), t.end(), x);
        int idx1 = itr1 - s.begin();
        int idx2 = itr2 - t.begin();
    
        ll ans = 1LL << 60;;
        ll tmp = 0;
        // 神社：右、寺：左
        if (idx1 > 0 && idx2 < b) {
            tmp = abs(s[idx1-1] - x) + abs(t[idx2] - s[idx1-1]);
            ans = min(tmp, ans);
            tmp = abs(t[idx2] - x) + abs(s[idx1-1] - t[idx2]);
            ans = min(tmp, ans);
        }

        // 神舎：右、寺：右
        if (idx1 > 0 && idx2 > 0) {
            ll y = s[idx1-1];
            ll z = t[idx2-1];
            tmp = abs(y - x) + abs(z - y);
            ans = min(ans, tmp);
            tmp = abs(z - x) + abs(y - z);
            ans = min(ans, tmp);
        }

        // 神社：左、寺：左
        if (idx1 < a && idx2 < b) {
            ll y = s[idx1];
            ll z = t[idx2];
            tmp = abs(y - x) + abs(z - y);
            ans = min(ans, tmp);
            tmp = abs(z - x) + abs(y - z);
            ans = min(ans, tmp);
        }

        // 神社：左、寺：右
        if (idx1 < a && idx2 > 0) {
            ll y = s[idx1];
            ll z = t[idx2-1];
            tmp = abs(y - x) + abs(z - y);
            ans = min(ans, tmp);
            tmp = abs(z - x) + abs(y - z);
            ans = min(ans, tmp); 
        }
        
        cout << ans << endl;
        
    }

    return 0;
}
