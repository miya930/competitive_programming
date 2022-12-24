#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n-1; i++) cin >> a[i];
    for (int i = 0; i < n-2; i++) cin >> b[i];

    vector<int> dp(n+1, inf), ans(n+1, -1);
    dp[0] = 0; ans[0] = 0;

    for (int i = 0; i < n; ++i) {
        if (i < n-1) {
            if (dp[i+1] > dp[i] + a[i]) {
                dp[i+1] = dp[i] + a[i];
                ans[i+1] = i;
            }
        }
        if (i < n-2) {
            if (dp[i+2] > dp[i] + b[i]) {
                dp[i+2] = dp[i] + b[i];
                ans[i+2] = i;
            }
        }
    }

    int cur = n-1;
    vector<int> output;
    while(1) {
        output.push_back(cur+1);
        cur = ans[cur];
        if (cur == 0) {
            output.push_back(cur+1);
            break;
        }
    }

    reverse(output.begin(), output.end());

    cout << output.size() << endl;
    for (int i = 0; i < (int)output.size(); i++) cout << output[i] << " ";
    cout << endl;

    return 0;
}
