#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1001001001;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> pa(n);
    for (int i = 0; i < n; i++) cin >> pa[i].first;
    for (int i = 0; i < n; i++) cin >> pa[i].second;

    sort(pa.begin(), pa.end());
    vector<int> dp(n+1, inf);
    for (int i = 0; i < n; i++) {
        auto itr = lower_bound(dp.begin(), dp.end(), pa[i].second);
        *itr = pa[i].second;
    }
    cout << n + lower_bound(dp.begin(), dp.end(), inf) - dp.begin() << endl;

    return 0;
}
