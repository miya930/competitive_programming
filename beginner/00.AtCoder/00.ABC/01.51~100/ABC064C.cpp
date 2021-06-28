#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 399) mp[0]++;
        else if (a[i] <= 799) mp[1]++;
        else if (a[i] <= 1199) mp[2]++;
        else if (a[i] <= 1599) mp[3]++;
        else if (a[i] <= 1999) mp[4]++;
        else if (a[i] <= 2399) mp[5]++;
        else if (a[i] <= 2799) mp[6]++;
        else if (a[i] <= 3199) mp[7]++;
        else cnt++;
    }
    bool flag = false;
    int ans_min, ans_max;
    if (cnt == n) flag = true;

    if (flag) {
        ans_min = 1;
        ans_max = cnt;
    } else {
        ans_min = mp.size();
        ans_max = ans_min + cnt;
    }

    cout << ans_min << " " << ans_max << endl;
}
