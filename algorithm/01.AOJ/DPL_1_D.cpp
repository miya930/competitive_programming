/***
 * Qiita記事より
 * 最長増加部分列を O(nlogn) で解く解法
 * https://qiita.com/drken/items/68b8503ad4ffb469624c#2-%E5%80%8B%E6%95%B0%E5%88%B6%E9%99%90%E3%81%AA%E3%81%97%E3%83%8A%E3%83%83%E3%83%97%E3%82%B5%E3%83%83%E3%82%AF%E3%81%AE%E5%A0%B4%E5%90%88
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const long long INF = 1LL << 60;

int LIS(const vector<long long>& a) {
    int n = (int)a.size();
    vector<long long> dp(n + 1, INF);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);

        *it = a[i];
    }

    return lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
}

int main()
{
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << LIS(a) << endl;

    return 0;
}
