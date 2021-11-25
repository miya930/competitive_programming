#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    vector<pair<ll, int>> sum(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        sum[i].first = a[i] + b[i];
        sum[i].second = i;
    }

    sort(sum.rbegin(), sum.rend());

    ll asum = 0, bsum = 0;

    for (int i = 0; i < n; ++i) {
        if (i%2==0) asum += a[sum[i].second];
        else bsum += b[sum[i].second];
    }

    cout << asum - bsum << endl;

    return 0;
}
