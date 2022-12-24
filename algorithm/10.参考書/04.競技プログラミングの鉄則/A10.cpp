#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int d;
    cin >> d;
    vector<int> l(d), r(d);
    for (int i = 0; i < d; i++) cin >> l[i] >> r[i];

    vector<int> suml(n+1), sumr(n+1);
    suml[1] = a[1];
    for (int i = 2; i <= n; i++) {
        suml[l] = max(suml[i-1], a[i])
    }
    sumr[n] = a[n];
    for (int i = n-1; i >= 0; i--) {
        sumr[i] = max(sumr[i+1], a[i]);
    }

    for (int i = 0; i < d; ++i) {
        cout << max(suml[l[i]-1], sumr[r[i]+1]);
    }

    return 0;
}
