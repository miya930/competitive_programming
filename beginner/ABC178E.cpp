#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1LL<<60;

int main()
{
    int n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    vector<ll> z(n), w(n);
    for (int i = 0;i < n; ++i){
        z[i] = x[i] + y[i];
        w[i] = x[i] - y[i];
    }

    ll z_max = 0, w_max = 0;
    ll z_min = INF, w_min = INF;
    for (int i = 0; i < n; ++i) {
        z_max = max(z_max, z[i]);
        z_min = min(z_min, z[i]);
        w_max = max(w_max, w[i]);
        w_min = min(w_min, w[i]);
    }
    cout << max(z_max - z_min,  w_max - w_min) << endl;
    return 0;

}
