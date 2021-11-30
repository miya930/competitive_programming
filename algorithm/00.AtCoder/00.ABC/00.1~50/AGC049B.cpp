#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    string s, t;
    cin >> n >> s >> t;
    queue<ll> que;

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (que.size()) {
            if (s[i] == '1') {
                ans += (i - que.front());
                que.pop();
            }
            
            if (t[i] == '1') que.push(i);

        } else if (s[i] != t[i]) {
            que.push(i);
        }
    }

    if (que.size()) ans = -1;

    cout << ans << endl;

    return 0;
}
