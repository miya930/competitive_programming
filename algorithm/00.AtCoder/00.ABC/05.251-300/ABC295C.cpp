#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = 0;
    for (auto x : mp) {
        ans += x.second / 2;
    }

    cout << ans << endl;
    return 0;
}
