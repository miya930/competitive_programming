#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) swap(a[i], b[i]);
    }

    ll s = 0, t = 0;
    ll cnt = 1;
    for (int i = n-1; i >= 0; i--) {
        cnt %= mod;
        s += ((a[i] - '0') * cnt);
        s %= mod;
        t += ((b[i] - '0') * cnt);
        t %= mod;
        cnt *= 10;
    }

    cout << s * t % mod << endl;

    return 0;
}
