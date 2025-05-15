
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<double> c(n);
    vector<vector<int>> s(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> c[i] >> p;
        s[i].resize(p);
        for (int j = 0; j < p; j++) cin >> s[i][j];
    }

    for (int i = 0; i < n; i++) {
        double zero = 0;
        vector<int> vec;
        for (int j = 0; j < s[i].size(); j++) {
            if (s[i][j] == 0) zero++;
            else vec.push_back(s[i][j]);
        }
        c[i] = c[i] * (double)s[i].size() / (s[i].size() - zero);
        s[i] = vec;
    }

    vector<double> dp(m+1, 2002002002);
    dp[m] = 0;
    for (int i = m-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            double sum = 0;
            for (int k = 0; k < s[j].size(); k++) {
                if (i + s[j][k] <= m) sum += dp[i+s[j][k]];
            }

            dp[i] = min(dp[i], c[j]+sum / s[j].size());
        }
    }
    printf("%.10lf\n", dp[0]);
    return 0;
}
