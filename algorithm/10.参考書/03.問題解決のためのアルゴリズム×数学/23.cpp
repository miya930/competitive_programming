#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll suma = 0, sumb = 0;
    for (int i = 0; i < n; ++i) {
        suma += a[i];
        sumb += b[i];
    }

    float ans = (float)(suma+sumb)/n;
    printf("%.10f\n", ans);

    return 0;
}
