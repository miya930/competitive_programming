#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
const int MAX_N = 1000100;

int main()
{
    vector<int> tri(200, 0), fo(1500, 0);
    for (int i = 1; i < (int)tri.size(); ++i) tri[i] = tri[i-1] + i;
    for (int i = 1; i < (int)fo.size(); ++i) fo[i] = fo[i-1] + tri[i];
    vector<int> dp(1000100, INF), odp(1000100, INF);
    for (int i = 0; i < (int)dp.size(); ++i) {
        dp[i] = i;
        odp[i] = i;
    }

    for (int i = 0; i <= MAX_N; ++i) {
        for (int j = 0; j < 182; ++j) {
            if (i+fo[j] <= MAX_N) dp[i+fo[j]] = min(dp[i+fo[j]], dp[i]+1);
            if (fo[j]%2==1) {
                if (i+fo[j] <= MAX_N) odp[i+fo[j]] = min(odp[i+fo[j]], odp[i]+1);
            }
        }
    }

    while (1) {
        int n; cin >> n;
        if (!n) break;       

        cout << dp[n] << " " << odp[n] << endl;
    }
    
    return 0;
}
