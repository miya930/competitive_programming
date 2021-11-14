#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<long long, long long> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]]++;
    }

    long long ans = 1;
    ans = a.size() * (a.size() - 1) / 2;
   
    for (auto x : mp) {
        ans -= (x.second - 1) * (x.second) / 2;
    }
   
    cout << ans << endl;

}

