#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    long long d;
    cin >> d >> n >> m;
    vector<long long> a(n+1), k(m);
    for (int i = 1; i <= n-1; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> k[i];

    a[0] = 0;
    a[n] = d;

    sort(a.begin(), a.end());

    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        int iter = lower_bound(a.begin(), a.end(), k[i]) - a.begin();
        int iter_2 = iter;
        if (iter > 0) iter_2--;

        ans += min((long long)abs(a[iter]-k[i]), (long long)abs(a[iter_2]-k[i]));
    }
    cout << ans << endl;
}
