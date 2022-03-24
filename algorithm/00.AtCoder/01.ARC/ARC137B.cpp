#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int mn = 0, mx = 0, cur = 0, x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) cur--;
        else cur++;
        chmin(x, cur-mx);
        chmax(y, cur-mn);
        chmin(mn, cur);
        chmax(mx, cur);
    }
    cout << y-x+1 << endl;

    return 0;
}
