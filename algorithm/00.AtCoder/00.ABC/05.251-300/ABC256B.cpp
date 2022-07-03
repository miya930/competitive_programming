#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<bool> koma(4, false);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        koma[0] = true;
        for (int j = 3; j >= 0; --j) {
            if (koma[j] == true) {
                koma[j] = false;
                if (j+a[i] > 3) {
                    ans++;
                } else {
                    koma[j+a[i]] = true;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
