#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    long long med_a = 0, med_b = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    med_a = a[n/2];
    med_b = b[n/2];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i]-med_a) + abs(b[i] - a[i]) + abs(b[i] - med_b);
    }
    cout << ans << endl;
}
