#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const long long INF = 1LL << 60;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<long long> > dp(n, vector<long long>(n, INF));

    for (int i = 0; i < n; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        dp[a][b] = w;
    }
    for (int i = 0; i < n; ++i) dp[v][v] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    bool exist_negative_cycle = false;

    for (int v = 0; v < n; ++v) {
        if (dp[v][v] < 0) exist_negative_cycle = true;        
    }
    if (exist_negative_cycle) {
        cout << "NEGATIVE_CYCLE" << endl;
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j) cout << " ";
                if (dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }

}
