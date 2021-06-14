#include <iostream>
#include <vector>
using namespace std;

int bin(int m) {
    int res = 0;
    int mul = 1;
    while (mul < m) {
        res++;
        mul *= 2;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    double ans = 0;
    for (int i = 1; i <= n; ++i) {
        int k_ = (k + (i - 1)) / i;
        double score_i = 1;
        for (int j = 0; j < bin(k_); ++j) {
            score_i /= 2;
        }
        ans += score_i / n;
    }
    printf("%.12lf\n", ans);
}
