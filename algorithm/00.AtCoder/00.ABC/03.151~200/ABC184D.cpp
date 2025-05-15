#include <bits/stdc++.h>
using namespace std;
using ll = long long;
double dp[110][110][110];

double func(int a, int b, int c) {
    if (dp[a][b][c]) return dp[a][b][c];
    if (a == 100 || b == 100 || c == 100) return 0;

    double ans = 0;
    ans += (func(a+1, b, c) + 1) * a / (a + b + c);
    ans += (func(a, b+1, c) + 1) * b / (a + b + c);
    ans += (func(a, b, c+1) + 1) * c / (a + b + c);
    dp[a][b][c] = ans;
    return ans;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    printf("%.10f\n", func(a, b, c));

    return 0;
}
