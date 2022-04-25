#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> func(int n) {
    vector<int> res;
    for (int i = 1; i*i <= n; ++i) {
        if (n%i != 0) continue;
        res.push_back(i);

        if (n/i != i) res.push_back(n/i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int,int> mp;
    ll ans = 0;
    for (int i = 0; i < n; ++i) mp[a[i]]++;

    for (int i = 0; i < n; ++i) {
        vector<int> t = func(a[i]);
        for (int j = 0; j < (int)t.size(); ++j) {
            int c1 = mp[t[j]];
            int c2 = mp[a[i]/t[j]];
            ans += 1LL * c1 * c2;
        }
    }

    cout << ans << endl;
    return 0;
}
