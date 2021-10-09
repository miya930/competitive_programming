#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;

template<class T> void chmin(T& a, T b) {
    if (a > b) a = b;
}

template<class T> void chmax(T& a, T b) {
    if (a < b) a = b;
}

int main()
{
    int n, Q;
    cin >> n >> Q;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    // 45ÅãâÒì]
    for (int i = 0; i < n; ++i) {
        ll t1 = x[i] - y[i];
        ll t2 = x[i] + y[i];
        x[i] = t1;
        y[i] = t2;
    }

    long long max_x = -INF, min_x = INF, max_y = -INF, min_y = INF;
    for (int i = 0; i < n; ++i) {
        chmax(max_x, x[i]);
        chmax(max_y, y[i]);
        chmin(min_x, x[i]);
        chmin(min_y, y[i]);
    }

    for (int i = 0; i < Q; ++i) {
        int q; cin >> q;
        int t = q;
        t--;

        // xê¨ï™åvéZ
        ll t1 = abs(x[t] - max_x);
        ll t2 = abs(x[t] - min_x);
        ll t3 = abs(y[t] - max_y);
        ll t4 = abs(y[t] - min_y);
        cout << max({ t1, t2, t3, t4 }) << endl;
    }

    return 0;
}
