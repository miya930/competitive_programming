#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, K;
vector<int> a, m;
vector<vector<bool> > dp;

int main()
{
    cin >> n >> K; 
    a.resize(n);
    m.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> m[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= K; ++j) {
            for (int k = 0; k <= m[i] && k * a[i] <= j; ++k) {
                dp[i+1][j] |= dp[i][j - k*a[i]];
            }
        }
    }

}
