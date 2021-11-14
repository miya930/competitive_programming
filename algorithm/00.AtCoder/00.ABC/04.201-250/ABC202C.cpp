#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    
    map<ll, ll> mp;
    for (int i = 0; i < n; ++i) mp[b[c[i]-1]]++;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[a[i]] != 0) res += mp[a[i]];
    }
    cout << res << endl;
}

