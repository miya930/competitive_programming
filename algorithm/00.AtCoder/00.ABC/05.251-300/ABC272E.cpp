#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> vec(m+1);
    for (int i = 0; i < n; i++) {
        if (a[i] >= n) continue;
        
        ll l = a[i] >= 0 ? 1 : (-a[i] + i) / (i + 1);   // +になる最初の数(分子は繰り上げ)
        ll r = min(m+1, (n - a[i] + i) / (i + 1));
        
        for (int j = l; j < r; j++) {
            vec[j].push_back(a[i]+(i+1)*j);
        }
    }

    for (int j = 1; j <= m; j++) {
        int sz = vec[j].size();
        vector<bool> ex(sz+1, false);
        for (auto x : vec[j]) {
            if (x < sz) ex[x] = true;
        }

        int res = 0;
        while(ex[res]) res++;
        cout << res << endl;
    }

    return 0;
}
