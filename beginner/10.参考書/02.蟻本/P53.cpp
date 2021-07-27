#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp;
int n, W;

// ƒƒ‚‰»Ä‹A‚ÅŒvZ—Ê‚Ì‰ü‘P
int rec(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];

    int res;
    if (i == n) {
        res = 0;
    } else if (j < w[i]) {
        res = rec(i+1, j);
    } else {
        res = max(rec(i+1, j), rec(i+1, j-w[i])+v[i]);
    }
    return res;
}

int main()
{

}
