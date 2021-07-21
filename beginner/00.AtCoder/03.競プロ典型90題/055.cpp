#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                for (int l = k+1; l < n; ++l) {
                    for (int m = l+1; m < n; ++m) {
                        if (1LL*a[i]*a[j]%p*a[k]%p*a[l]%p*a[m]%p == q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
