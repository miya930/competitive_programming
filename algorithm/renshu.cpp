#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26, 0);
    for (int i = 0 ;i < n; ++i) cnt[s[i] - 'a']++;

    int l = 0, r = n-1;
    while(r-l>0) {
        int x = s[l] - 'a'; 
        for (int i = 0; i < x; ++i) {
            if (!cnt[i]) continue;
            while(l < r && s[r] - 'a' != i) {
                cnt[s[r] - 'a']--;
                r--;
            }
            swap(s[l], s[r]);
            cnt[i]--;
            r--;
            break;
        }
        l++;
    }

    return 0;
}
