#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = {0, -1, 0, 1, 1, -1, 1, -1};
int dy[] = {-1, 0, 1, 0, 1, -1, -1, 1};

int main()
{
    int n; 
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll tmp1 = 0;
            ll pp = 1;
            for (int ii = 0; ii < n-1; ++ii) pp *= 10;

            tmp1 += (pp * (a[i][j] - '0'));
            int nx = i;
            int ny = j;

            for (int k = 0; k < 8; ++k) {
                ll tmp2 = tmp1;
                nx = i;
                ny = j;
                for (int l = n-2; l >= 0; --l) {
                    nx = nx + dx[k];
                    ny = ny + dy[k];

                    if (nx < 0)  nx = n-1;
                    if (nx >= n) nx = 0;
                    if (ny < 0)  ny = n-1;
                    if (ny >= n) ny = 0;

                    ll p = 1;
                    for (int m = 0; m < l; ++m) p *= 10;

                    tmp2 += (p * (a[nx][ny] - '0'));

                }
                ans = max(ans, tmp2);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
