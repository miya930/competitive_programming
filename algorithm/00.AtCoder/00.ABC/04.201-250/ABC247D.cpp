#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int Q;
    cin >> Q;

    deque<pair<ll,ll>> dq;
    for (int q = 0; q < Q; ++q) {
        int t;
        cin >> t;

        if (t == 1) {
            ll x, c;
            cin >> x >> c;
            dq.push_back({x, c});
        } else {
            ll c;
            cin >> c;

            ll ans = 0;
            while(c > 0) {
                ll a = dq.front().first;
                ll b = dq.front().second;

                if (b == c) {
                    ans += a*b;
                    cout << ans << endl;
                    dq.pop_front();
                    break;
                } else if (b > c) {
                    ans += a*c;
                    cout << ans << endl;
                    b -= c;
                    dq.pop_front();
                    dq.push_front({a, b});
                    break;
                } else {
                    ans += a*b;
                    c -= b;
                    dq.pop_front();
                }
            }
        }
    }

    return 0;
}
