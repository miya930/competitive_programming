#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int n;
int dp[1<<20][20];
int dist[20][20];

int func(int s, int v) {
    if (s == 0) {
        if (v == 0){
            return 0;
        } else {
            return inf;
        }
    }

    if ((s & (1<<v)) == 0) return inf;  // v が Sに含まれている

    int ret = dp[s][v];
    if (ret != 0) return dp[s][v];

    ret = inf;
    for (int i = 0; i < n; ++i) {
        int tmp = func(s ^ (1<<v), i) + dist[i][v];  // ゴールから逆順にたどっている
        if (tmp < ret) ret = tmp;
    }

    return dp[s][v] = ret;
}

int main()
{


    return 0;
}
