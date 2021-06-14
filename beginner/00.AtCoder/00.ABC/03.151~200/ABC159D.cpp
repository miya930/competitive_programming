#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MA = 200100;
vector<long long> cnt(MA, 0);

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long all = 0;
    for (int i = 0; i < n; ++i) cnt[a[i]]++;
    for (int i = 1; i <= n; ++i) all += cnt[i] * (cnt[i] - 1) / 2;

    for (int i = 0; i < n; ++i) {
        long long ans = all;
        ans -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
        ans += (cnt[a[i]] - 1) *(cnt[a[i]] - 2) /2;
        cout << ans << endl;
    }
    
}
