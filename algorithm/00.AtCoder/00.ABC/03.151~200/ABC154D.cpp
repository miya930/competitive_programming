#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n,k;
    cin >> n >> k;
    vector<int> p(n);
    int ma = 0;
    for (int i= 0; i < n; ++i) {
        cin >> p[i];
        ma = max(ma, p[i]);
    }

    vector<ll> sum(ma+1, 0);
    for (int i = 0; i < ma; ++i) sum[i+1] = sum[i] + i + 1;

    double tmp = 0;
    for (int i = 0; i < k; ++i) {
        tmp += ((double)sum[p[i]]/p[i]);
    }

    double ans = tmp;
    for (int i = k; i < n; ++i) {
        tmp = tmp - (double)sum[p[i-k]]/p[i-k];
        tmp = tmp + (double)sum[p[i]]/p[i];
        ans = max(ans, tmp);
    }

    printf("%.12f\n", ans);
    return 0;
}
