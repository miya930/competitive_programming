#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; ++i) mp[a[i]]++;


    long long ans = 0;
    for (auto x : mp) {
        if (x.first < x.second) ans += (long long)x.second - (long long)x.first;
        else if (x.first > x.second) ans += (long long)x.second;
    }
    cout << ans << endl;

}
