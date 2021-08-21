#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            double cnt = 0;
            double temp = (r[i]-l[i]+1) * (r[j]-l[j]+1);
            for (int k = l[i]; k <= r[i]; ++k) {
                for (int m = l[j]; m <= r[j]; ++m) {
                    if (k > m) cnt++;
                    
                }
            }
            ans += (cnt/temp);
        }
    }
    
    printf("%.10f\n", ans);
    
}
