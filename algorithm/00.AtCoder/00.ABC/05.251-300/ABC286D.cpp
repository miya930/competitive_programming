#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool dp[60][300000];

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    dp[0][0] = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < x; j++) {
            if (dp[i][j]) {
                dp[i+1][j] = true;
                for (int k = 1; k <= b[i]; k++) {
                    if (j+a[i]*k <= x) dp[i+1][j+a[i]*k] = true;
                }
            }
        }
    }

    bool isok = false;
    for (int i = 0; i <= n; i++) {
        if (dp[i][x]) isok = true;
    }

    if (isok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
