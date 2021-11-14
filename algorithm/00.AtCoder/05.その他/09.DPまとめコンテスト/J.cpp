#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
double dp[320][320][320];
int n;

double func(int c1, int c2,  int c3) {
    if (c1 == 0 && c2 == 0 && c3 == 0) return 0;
    if (dp[c1][c2][c3] >= 0) return dp[c1][c2][c3];
    double fans = 1.0 / (1-(double)(n-c1-c2-c3)/n);
    if(c1>0) fans+=func(c1-1, c2, c3) * c1/n / (1.0-(double)(n-c1-c2-c3)/n);
    if(c2>0) fans+=func(c1+1, c2-1, c3) * c2/n / (1.0-(double)(n-c1-c2-c3)/n);
    if(c3>0) fans+=func(c1, c2+1, c3-1) * c3/n / (1.0-(double)(n-c1-c2-c3)/n);
    return dp[c1][c2][c3]=fans;
}

int main()
{
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i <= 310; ++i) {
        for (int j = 0; j <= 310; ++j) {
            for (int k = 0; k <= 310; ++k) {
                dp[i][j][k] = -1;
            }
        }
    }
    
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i]==1) one++;
        if (a[i]==2) two++;
        if (a[i]==3) three++;
    }
    
    printf("%.10f\n", func(one, two, three));
    return 0;
    
}
