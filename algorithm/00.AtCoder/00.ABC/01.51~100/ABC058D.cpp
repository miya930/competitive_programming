#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int mod = 1000000007;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n), y(m);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < m; ++i) cin >> y[i];

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    ll tmpx = 0;
    ll tmpy = 0;

    for (int i = 1; i < n; ++i) {
        tmpx += i*x[i];
        tmpx %= mod;
    }
    for (int i = 0; i < n-1; ++i) {
        tmpx -= (n-i-1)*x[i];
        tmpx = (tmpx + mod) % mod;
    }
    for (int i = 1; i < m; ++i) {
        tmpy += i*y[i];
        tmpy %= mod;
    }
    for (int i = 0; i < m-1; ++i) {
        tmpy -= (m-i-1)*y[i];
        tmpy = (tmpy + mod) % mod;
    }

    cout << tmpx * tmpy % mod << endl;

}
