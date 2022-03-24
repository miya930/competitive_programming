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


/* 2022.3.20 復習 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >>n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int r = 0;
    int cnt = 0;
    int ans = 0;
    map<int,int> mp;
    for (int l = 0; l < n; ++l) {
        while(r < n && cnt <= k) {
            if (mp[a[r]] == 0) {
                if (cnt == k) break;
                cnt++;
            } 
            mp[a[r]]++;
            r++;
        }
        ans = max(ans, r-l);
        if (r == l) r++;
        mp[a[l]]--;    
        if (mp[a[l]] == 0) cnt--;
    }

    cout << ans << endl;
    return 0;
}

