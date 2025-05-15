#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int m;
    cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; i++) cin >> d[i];
    vector<int> sum(m+1, 0);
    for (int i = 0; i < m; i++) {
        sum[i+1] = sum[i] + d[i];
    }
    int half = (sum[m]+1)/2;

    int idx = lower_bound(sum.begin(), sum.end(), half) - sum.begin();

    int cur = 0;
    for (int i = 0 ;i < m; i++) {
        if (half - d[i] > 0) {
            half -= d[i];
        } else {
            cout << i+1 << " " << half << endl;
            return 0;
        }
    }

    return 0;
}
