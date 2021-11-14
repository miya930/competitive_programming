#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    map<int, int> mp, ans;

    for (int i = 0; i < n; ++i) {
        mp[a[i]]++;
        mp[a[i]+b[i]]--;
    }

    int past = 0;
    int num = 0;
    for (auto x: mp) {
        ans[num] += (x.first-past);
        past = x.first;
        num += x.second;
    }

    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;

}
