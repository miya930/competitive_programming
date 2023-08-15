#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> T gcd(T n, T m) {
    if (m == 0) return n;
    else return gcd(m, n%m);
}

int main()
{
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        ll n, d, k;
        cin >> n >> d >> k;
        k--;
        int a = n / gcd(n, d);
        cout << d * k % n + k / a << endl;
    }

    return 0;
}
