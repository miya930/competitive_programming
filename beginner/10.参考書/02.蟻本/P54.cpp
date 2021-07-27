#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
int n, W;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

void solve() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= W; ++j) {
            chmax(dp[i+1][j+1], dp[i][j]);
            if(j-w[i]>=0) chmax(dp[i+1][j], dp[i][j-w[i]]+v[i]);
        }
    }
}
