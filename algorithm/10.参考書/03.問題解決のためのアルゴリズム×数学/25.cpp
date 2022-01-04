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

    double suma = 0, sumb = 0;
    double ans = 0.0;
    
    for (int i = 0; i < n; ++i) {
        suma += a[i];
        sumb += b[i];
    }

    ans = (suma + sumb*2)/3;

    printf("%.12f\n", ans);

    return 0;
}
