#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const long long INF = 10000000007LL;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = INF;
    for (int i = 0; i < m; ++i) {
        int iter_1 = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int iter_2 = iter_1;
        if (iter_1 > 0) iter_2 = iter_1 - 1;
        //cout << iter_1 << " " << iter_2 << endl;

        if (iter_1 < n) ans = min(ans, (long long)abs(a[iter_1]-b[i]));
        if (iter_2 < n) ans = min(ans, (long long)abs(a[iter_2]-b[i]));
        
    }
    cout << ans << endl;

}
