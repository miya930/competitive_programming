#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > dp;
int n, m, M;

int main()
{
    cin >> n >> m >> M;
    dp.assign(n+1, vector<int>(m+1, 0)); // dp[i][j]FiŒÂ‚ğj•ªŠ„‚·‚éê‡‚Ì”
    dp[0][0] = 1;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++i) {
            dp[i+1][j+1] = 
        }
    }
}
