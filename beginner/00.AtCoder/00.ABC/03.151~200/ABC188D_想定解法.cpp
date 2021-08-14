#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, C;
    cin >> n >> C;
    vector<long long> a(n), b(n), c(n);
    vector<pair<long, long> > pa;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }

    for (int i = 0; i < n; ++i) {
        pa.push_back(make_pair(a[i], c[i]));
        pa.push_back(make_pair(b[i]+1, -c[i]))
    }

    sort(pa.begin(), pa.end());

    long long sum = 0;
    long long ans = 0;
    long long prev = 0;
    for(auto x : pa) {
        ans += min(sum, C) * (x.first - prev);
        sum += x.second;
        prev = x.first;
    }
    cout << ans << endl;
}
