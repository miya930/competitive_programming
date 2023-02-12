#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    int x;
    cin >> x;

    vector<bool> dp(200000);
    vector<bool> ismochi(200000);
    for (int i = 0; i < m; i++) ismochi[b[i]] = true;
    dp[0] = true;

    for (int j = 0; j <= 100000; j++) {
        for (int i = 0; i < n; i++) {
            if (j+a[i] <= x && dp[j] == true && ismochi[j] == false) dp[j+a[i]] = true; 
        }
    }

    if (dp[x]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
