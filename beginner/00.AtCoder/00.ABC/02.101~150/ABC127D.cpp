#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
vector<pair<int, int> > b;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    b.resize(m);

    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i].second >> b[i].first;

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    long long ans = 0;
    int idx = 0;
    for (auto x : b) {
        int i = 0;
        while (idx + i < n && i < x.second && a[idx + i] < x.first) i++;
        ans += (long long)x.first * i;
        idx += i;
    }

    for (int i = idx; i < n; ++i) ans += a[i];

    cout << ans << endl;
}
