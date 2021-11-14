#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) cin >> c[i];
 
    map<int, int> mp;

    int ans = 0;
    
    for (int i = 0; i < k-1; ++i) mp[c[i]]++;
    int right = k-1;

    for (int left = 0; left < n; ++left) {
        if (right == n) break;
        mp[c[right]]++;
        ans = max(ans, (int)mp.size());
        mp[c[left]]--;
        if (mp[c[left]] == 0) mp.erase(c[left]);
        right++;
    }

    cout << ans << endl;
    return 0;
}
