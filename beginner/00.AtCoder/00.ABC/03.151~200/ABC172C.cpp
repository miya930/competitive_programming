#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0 ; i < n; ++i) cin >> a[i];
    for (int i = 0 ; i < m; ++i) cin >> b[i];
    
    vector<long long> asum(n+1,0), bsum(m+1, 0);

    for (int i = 0; i < n; ++i) asum[i+1] = asum[i] + a[i];
    for (int i = 0; i < m; ++i) bsum[i+1] = bsum[i] + b[i];

    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (k - asum[i] < 0) continue;
        long long sum;
        int index = upper_bound(bsum.begin(), bsum.end(), k - asum[i]) - bsum.begin();
        index--;
        ans = max(ans, (long long)(i+index));
    }

    cout << ans << endl;

}
