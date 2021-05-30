#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > x(m);
    for (int i = 0; i < m; ++i) cin >> x[i].first >> x[i].second;

    vector<vector<int> > dp(2*n+1, vector<int>(2*n+1, 0));
    vector<int> pos_y;

    dp[0][n] = 1;
    sort(x.begin(), x.end());
    long long ans = 1;
    pos_y.push_back(n);

    for (int i = 0; i < m; ++i) {
        
    }
}