#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> sum(n+1), sumz(n+1);
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                sum[i+1] = sum[i] + 1;
                sumz[i+1] = sumz[i];
                m++;
            } else if (s[i] == '0') {
                sum[i+1] = sum[i];
                sumz[i+1] = sumz[i] + 1;
            } else {
                sum[i+1] = sum[i];
                sumz[i+1] = sumz[i];
            }
        }

        int ans = 0;
        for (int i = 0; i <= n-k; i++) {
            int one = sum[i+k] - sum[i];
            int zero = sumz[i+k] - sumz[i];
            if (zero == 0 && one == m) {
                ans++;
            }
        }
        if (ans == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
