#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;

int main()
{
    int t; cin >> t;
        for (int tt = 0; tt < t; ++tt) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        int ans = INF;
        int right = 0;
        int sum = 0;
        for (int left = 0; left < n; ++left) {
            while(right < n && sum < s) {
                sum += a[right++];
            }
            if (sum < s) break;
            ans = min(ans, right - left);
            if (left == right) right++;
            else sum -= a[left];
        }
    
        if (ans > n) cout << 0 << endl;
        else cout << ans << endl;
    }
}
