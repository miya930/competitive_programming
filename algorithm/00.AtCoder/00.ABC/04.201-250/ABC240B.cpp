#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int,int> mp;
    for (int i = 0; i < n;++i) mp[a[i]]++;
    cout << mp.size() << endl;

    return 0;
}
