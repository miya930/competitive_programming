#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        b.push_back(abs(a[i]-a[i+1]));
    }
    ll g = 0;

    for (int i = 0; i < b.size(); i++) {
        g = gcd(g, b[i]);
    }

    if (g == 0 || g >= 2) cout << 1 << endl;
    else cout << 2 << endl;

    return 0;
}
