#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long mx = x[(n-1)/2];
    long long my = y[(n-1)/2];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(mx-x[i]);
        ans += abs(my-y[i]);
    }
    cout << ans  << endl;
}
