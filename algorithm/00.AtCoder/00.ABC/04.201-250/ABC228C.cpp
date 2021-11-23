#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<vector<int>> p(n, vector<int>(3));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; j++) {
            cin >> p[i][j];
        } 
    }

    vector<int> sum(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            sum[i] += p[i][j];
        }
    }
    vector<int> vec = sum;

    sort(sum.rbegin(), sum.rend());

    for (int i = 0; i < n; ++i) {
        if (vec[i]+300 >= sum[k-1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}
