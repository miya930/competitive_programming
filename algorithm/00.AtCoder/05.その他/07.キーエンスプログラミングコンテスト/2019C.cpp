#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++i) sum1 += a[i];
    for (int i = 0; i < n; ++i) sum2 += b[i];
    
    if (sum1 < sum2) {
        cout << -1 << endl;
        return 0;
    }

    bool flag = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) flag = false;
    }

    if (flag) {
        cout << 0 << endl;
        return 0;
    }

    ll sum = 0;
    ll ans = 0;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            sum += (b[i]-a[i]);
            ans++;
        } else if (a[i] > b[i]) vec.push_back(a[i]-b[i]);
    }
    sort(vec.rbegin(), vec.rend());

    for (int i = 0; i < vec.size(); ++i) {
        ans++;
        sum -= vec[i];
        if (sum < 0) break;
    }

    cout << ans << endl;
    return 0;
}
