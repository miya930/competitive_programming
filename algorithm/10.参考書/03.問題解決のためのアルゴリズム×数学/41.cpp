#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int t, n;
    cin >> t >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];

    vector<ll> sum(t+1, 0);

    for (int i = 0; i < n; ++i) {
        sum[l[i]]++;
        sum[r[i]]--;
    }

    for (int i = 0; i <= t; ++i) sum[i+1] += sum[i];

    for (int i = 0; i < t; ++i) cout << sum[i] << endl;

    return 0;
}
