#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    if (n%2 == 0) {
        int ax = a[n/2] + a[n/2-1];
        int bx = b[n/2] + b[n/2-1];
        ans += (bx - ax + 1);
    } else {
        int ax = a[n/2];
        int bx = b[n/2];
        ans += (bx - ax + 1);
    }
    cout << ans << endl;
    return 0;
}
