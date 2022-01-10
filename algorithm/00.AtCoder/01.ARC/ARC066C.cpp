#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1000000007;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int,int> mp;
    for (int i = 0; i < n; ++i) mp[a[i]]++;

    bool flag = true;
    if (n%2 == 0) {
        int cnt = 1;
        for (auto x : mp) {
            if (x.first != cnt || x.second != 2) flag = false;
            cnt += 2;
        }
    } else {
        int cnt = 0;
        for (auto x : mp) {
            if (x.first == 0) {
                if (x.second != 1) flag = false;
            } else if (x.first != cnt || x.second != 2) flag = false;
            cnt += 2;
        }
    }

    ll ans = 1;
    for (auto x : mp) {
        ans *= x.second;
        ans %= mod;
    }

    if (flag) cout << ans << endl;
    else cout << 0 << endl;

    return 0;
}
