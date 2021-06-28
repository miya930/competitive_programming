#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
    }

    vector<long long> vec;
    int cnt = 0;
    for (auto x : mp) {
        if (x.second >= 2) {
            vec.push_back(x.first);
            cnt++;
        }
    }
    sort(vec.rbegin(), vec.rend());

    if (cnt < 2) cout << 0 << endl;
    else if (mp[vec[0]] >= 4) cout << vec[0] * vec[0] << endl;
    else cout << vec[0] * vec[1] << endl;

    return 0;
}
