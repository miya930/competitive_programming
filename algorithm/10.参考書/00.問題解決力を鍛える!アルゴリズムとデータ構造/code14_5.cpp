#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<long long> > dp(n, vector<long long>(n, inf));

    for (int i = 0; i < n; ++i) {
        int a, b;
        int w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }

    for (int i = 0; i < n; ++i) dp[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    bool exist_negative_cycle = false;

    for (int i = 0; i < n; ++i) {
        if (dp[i][i] < 0) exist_negative_cycle = true;
    }

    if (exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j) cout << " ";
                if (dp[i][j] < inf/2) cout << dp[i][j];
                else cout << endl;
            }
            cout << endl;
        }
    }

    return 0;
}
