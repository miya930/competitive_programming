#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    map<int, int> mp;

    int right = 0;
    int res = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && mp.size() <= k) {
            mp[a[right]]++;
            right++;
        }
        if (left == 0 && right == n) {
            res = max(res, right - left);
            break;
        } else {
            res = max(res, right - left - 1);
        }
        if (right == left) right++;
        else {
            mp[a[left]]--;
            if (mp[a[left]] <= 0) mp.erase(a[left]);
        }
    }
    cout << res << endl;
}
