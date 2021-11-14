#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    double ans = 0;
    sort(a.begin(), a.end());

    double x = a[(n - 1) / 2];

    for (int i = 0; i < n; ++i) {
        ans += x / 2 + a[i] - min((double)a[i], x);
    }
    printf("%.9lf\n", ans / n);
}
