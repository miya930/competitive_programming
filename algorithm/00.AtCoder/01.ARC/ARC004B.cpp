#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> d(n);
    int ma = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        ma = max(ma, d[i]);
        sum += d[i];
    }

    cout << sum << endl;
    if (ma > sum - ma) cout << ma - (sum-ma) << endl;
    else cout << 0 << endl; 

    return 0;
}
