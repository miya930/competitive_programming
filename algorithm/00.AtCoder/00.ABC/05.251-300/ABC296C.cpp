#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<ll,int> mp;
    for (int i = 0; i < n; i++) mp[a[i]] = 2;

    bool flg = false;
    for (int i = 0; i < n; i++) {
        auto itr = mp.find(a[i]+k);
        if (itr != mp.end()) flg = true;
    }

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
