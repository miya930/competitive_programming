/**
 * Å’·‹¤’Ê•”•ª—ñ
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
string s,t;

vector<vector<int> > dp;

void solve(){
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s[i]==t[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
}