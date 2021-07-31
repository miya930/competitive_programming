#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<vector<int> > Graph;
const int mod = 998244353;
int n, m, k;
long long ans;
vector<vector<long long> > dp;          // dp[k][i]Fk“ú–Ú‚É“ssi‚É‚¢‚éê‡‚Ì”

int main()
{   
    cin >> n >> m >> k;
    Graph G(n, 1);
    dp.assign(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
    }

    // ‰Šú‰»
    for (int i = 1; i < n; ++i) dp[1][i] = 1;

    for (int i = 1; i <= k; ++i) {
        long long val1 = 0, val2 = 0;

        for (int j = 0; j < n; ++j) {
            val1 += dp[i][j];             
        }

        for (int j = 1; j < n; ++j) {
            if () 
        }
    }
    
}
