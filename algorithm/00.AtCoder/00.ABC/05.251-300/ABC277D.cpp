#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; ++i) {
        a.push_back(m+a[i]);
    }
    sort(a.begin(), a.end());

    int cur = 0;
    ll ans = 0;
    ll tmp = a[cur]%m;
    int cnt = 0;
    while(1) {
        if (cur == a.size()-1) break;
        if ((a[cur] == a[cur+1]) || (((a[cur]+1)%m) == (a[cur+1]%m))) {
            tmp += (a[cur+1]%m);
            cnt++;
        } else {
            tmp = a[cur+1]%m;
            cnt = 0;
        }
        ans = max(ans, tmp);
        cur++;
        if (cnt == n) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << sum - ans << endl;
    return 0;
}
