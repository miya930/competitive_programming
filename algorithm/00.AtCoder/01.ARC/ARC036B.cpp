#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) cin >> h[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            int r = i;
            while (h[r] > h[r+1] && r < n-1) r++;
            ans = max(ans, r-i+1);
        } else if (i == n-1) {
            int l = i;
            while(h[l-1] < h[l] && l > 0) l--;
            ans = max(ans, i-l+1); 
        } else if (h[i-1] < h[i] && h[i] > h[i+1]) {
            int l = i, r = i;
            while (h[l-1] < h[l] && l > 0) l--;
            while (h[r] > h[r+1] && r < n-1) r++;

            ans = max(ans, r-l+1);
        }
    }

    cout << ans << endl;
    return 0;
}
