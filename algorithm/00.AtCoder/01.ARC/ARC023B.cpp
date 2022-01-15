#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int r, c, d;
    cin >> r >> c >> d;
    vector<vector<int>> a(r, vector<int>(c));
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) cin >> a[i][j];
    }

    int ans = 0;
    int even = 0, odd = 0;
    if (d <= r+c-2) {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i+j)<=d && (i+j)%2==d%2) ans = max(ans, a[i][j]);
            }
        }
    } else {
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if ((i+j)%2==0) even = max(even, a[i][j]);
                else odd = max(odd, a[i][j]);
            }
        }

        if (d%2 == 0) ans = even;
        else ans = odd;
    }

    cout << ans << endl;
    return 0;
}
