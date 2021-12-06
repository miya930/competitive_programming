#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n), h(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> h[i];

    for (ll cx = 0; cx <= 100; cx++) {
        for (ll cy = 0; cy <= 100; cy++) {
            bool flag = true;
            ll H = -1;

            for (int i = 0; i < n; ++i) {
                if (h[i] == 0) continue;
                
                if (H == -1) {
                    H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                } else {
                    if (H != (h[i] + abs(x[i]-cx) + abs(y[i]-cy))) {
                        flag = false;
                    }
                }
            }

            if (flag == false) continue;

            for (int i = 0; i < n; ++i) {
                ll height = max(H - abs(x[i]-cx) - abs(y[i]-cy),0LL);
                if (height != h[i]) flag = false;
            }

            if (flag) {
                cout << cx << " " << cy << " " << H << endl;
            }
        }
    }

    return 0;
}
