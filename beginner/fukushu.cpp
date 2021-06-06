#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, A;
    cin >> n >> A;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<vector<int> > dp(n+1, vector<int>(A, 0));
    dp[0][0] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= A; ++j) {
            dp[i+1][j] |= dp[i][j];
            if (j >= a[i]) dp[i+1][j] |= dp[i][j-a[i]];
        }
    }
    if (dp[n][A]) cout << "Yes" << endl;
    else cout << "No" << endl;
}
