#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int inf = 1001001001;
const ll infl = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    double ans = 0;
    int fo = 0;
    int ba = n-1;
    double fdist = a[fo];
    double bdist = a[ba];
    for (int i = 0; i < 2*n; ++i) {
        if (fo < ba) {
            if (fdist/b[fo] < bdist/b[ba]) {
                ans += fdist;
                bdist -= (fdist*b[ba]/b[fo]);
                fo++;
                fdist = a[fo];
            } else if (fdist/b[fo] > bdist/b[ba]) {
                fdist -=(bdist*b[fo]/b[ba]);
                ans += bdist*b[fo]/b[ba];
                ba--;
                bdist = a[ba];
            } else {
                ans += fdist;
                fo++;
                ba--;
                fdist = a[fo];
                bdist = a[ba];
                if (fo > ba) break;
            }
        } else {
            if (fdist > bdist) {
                ans += bdist/2.0;
            } else {
                ans += fdist/2.0;
            }
            break;
        }
    }
    printf("%.10f\n", ans);

    return 0;
}
