#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double inf = 1000000000000;

int main()
{
    int n ,k;
    cin >> n >> k;

    vector<int> a(k), x(n), y(n);
    map<int,int> mp;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        a[i]--;
        mp[a[i]]++;
    }
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (mp[i]) continue;
        double tmp = inf;
        for (int j = 0; j < k; ++j) {
            if (i == a[j]) continue;
            int cur = a[j];
            double diffx = ((double)x[i]-(double)x[cur]) * ((double)x[i]-(double)x[cur]);
            double diffy = ((double)y[i]-(double)y[cur]) * ((double)y[i]-(double)y[cur]);
            double diff = sqrt(diffx + diffy);
            tmp = min(diff, tmp);
         }
        ans = max(tmp, ans);
    }
 
    printf("%.10f\n", ans);
    return 0;
}
