#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    string s;
    int k;
    cin >> s >> k;

    int n = s.size();

    vector<int> sum(n+1, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '.') {
            sum[i+1] = sum[i]+1;
        } else {
            sum[i+1] = sum[i];
        }
    }

    int right = 0;
    int ans = 0;
    for (int left = 0; left < n; ++left) {
        while (right < n && sum[right+1]-sum[left] <= k) {
            right++;
        }
        ans = max(ans, right - left);
    }
    
    cout << ans << endl;

    return 0;
}
