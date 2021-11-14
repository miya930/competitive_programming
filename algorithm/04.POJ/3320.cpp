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
    
    map<int, int> mp, mp_sum;
    for (int i = 0; i < n; ++i) mp_sum[a[i]]++;
    int sum = mp_sum.size();

    int right = 0;
    int p = 0;
    int ans = n+1;
    for (int left = 0; left < n; ++left) {
        while(right < n && p < sum) {
            if (mp[a[right]] == 0) p++;
            mp[a[right]]++;
            right++;
        }
        if (p < sum) break;
        ans = min(ans, right - left); 
        if (left == right) right++;
        else {
            mp[a[left]]--;
            if (mp[a[left]] == 0) {
                mp.erase(a[left]);
                p--;
            }
        }
    }
    cout << ans << endl;

}
