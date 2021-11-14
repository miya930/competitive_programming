#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const double INF = 1000000007;

bool check(int k, double mid, int n, vector<ll> w, vector<ll> v) {
    vector<double> vec(n);
    for (int i = 0; i < n; ++i) {
        vec[i] = v[i] - mid * w[i];
    }
    sort(vec.rbegin(), vec.rend());

    double temp = 0;
    for (int i = 0; i < k; ++i) {
        temp += vec[i];
    }

    if (temp >= 0) return true;
    else return false;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> w(n), v(n);
    for (int i = 0; i < n; ++i) cin >> w[i] >> v[i];

    vector<ll> vec(n);

    double right = INF;
    double left = -1;

    while (right - left > 0.001) {
        double mid = (right + left) / 2;
        if (check(k, mid, n, w, v)) left = mid;
        else right = mid;
    }
    cout << left << endl;
}
