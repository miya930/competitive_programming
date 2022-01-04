#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                for (int l = k+1; l < n; ++l) {
                    for (int m = l+1; m < n; ++m) {
                        if (a[i]+a[j]+a[k]+a[l]+a[m] == 1000) ans++;
                    } 
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
