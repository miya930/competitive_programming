#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int dp[110][110];
const int INF = 1000000007;

int main()
{
    int p, q;
    cin >> p >> q;

    vector<int> a(q+2);
    for (int i = 1; i <= q; ++i) cin >> a[i];
    a[0] = 0;
    a[q+1] = p+1;

    for (int i = 0; i <= q; ++i) dp[i][i+1] = 0;

    for (int w = 2; w <= q+1; ++w) {
        for (int i = 0; i + w <= q+1; ++i) {
            int j = i + w, t = INF;

            for (int k = i + 1; k < j; ++k) {
                t = min(t, dp[i][k] + dp[k][j]);
            }

            dp[i][j] = t + a[j] - a[i] - 2;
        }
    }

    cout << dp[0][q+1] << endl;

}
